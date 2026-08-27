import random
import torch
from torch import nn
from torch.utils.data import DataLoader, TensorDataset
from tqdm import tqdm

class Model(nn.Module):
    def __init__(self):
        super().__init__()
        self.w = nn.Linear(51, 30)

    def forward(self, x, binarize=False):
        if binarize:
            bw = torch.sign(self.w.weight)
            y1 = torch.matmul(x, bw.T)
        else:
            y1 = self.w(x)
        z1 = torch.sum(y1[:, :15], dim=1, keepdim=True)
        z2 = torch.sum(y1[:, 15:], dim=1, keepdim=True)
        z = torch.cat((z1,z2), dim=1)
        return z
        # want z1 and z2 as one layer with dimension (batch size, 2)

def load_data():
    x = []
    y = []
    with open("./mnist2_train.txt") as f:
        lines = f.readlines()
        for line in lines:
            nums = list(map(int, line.split()))
            x.append(nums[:-1])
            y.append(nums[-1])
    x = torch.tensor(x, dtype=torch.float32)
    y = torch.tensor(y)
    return x, nn.functional.one_hot(y, num_classes=2).float(), y

images, labels, lab1 = load_data()
dataset = TensorDataset(images, labels)
data_loader = DataLoader(dataset, batch_size=16, shuffle=True)
model = Model()
optimizer = torch.optim.SGD(model.parameters(), lr=0.15)
loss = nn.BCEWithLogitsLoss()
scheduler = torch.optim.lr_scheduler.StepLR(optimizer, step_size=2, gamma=0.9999)
NUM_EPOCHS = 20

bestacc = 0
bestw = torch.tensor(1)

for epoch in range(NUM_EPOCHS):
    for batch_images, batch_labels in data_loader:
        optimizer.zero_grad()
        y = model(batch_images)
        L = loss(y, batch_labels)
        L.backward()
        optimizer.step()

    scheduler.step()

    with torch.no_grad():
        pred = model.forward(images, binarize=True)
        # Compute accuracy
        pred_cls = torch.argmax(pred, dim=1)
        correct = (pred_cls == lab1).sum()
        acc = (correct / lab1.size(0)).item()
        print(acc)
        if acc > bestacc:
            bestacc = acc
            bestw = model.w.weight.clone()

print(f"Final: ", bestacc)
n, m = model.w.weight.shape
sw = torch.sign(bestw).long()
#print(n, m)
with open("weights.txt", "w") as f:
    for i in range(n):
        for j in range(m):
            f.write(f"{sw[i][j].item()} ")
        f.write("\n")
