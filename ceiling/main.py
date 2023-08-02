class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, x):
        if self.root is None:
            self.root = Node(x)
            return

        def insert_rec(node, val, layer_id = 1):
            if val < node.value:
                if node.left is None:
                    node.left = Node(val)
                else:
                    insert_rec(node.left, val, layer_id + 1)
            else:
                if node.right is None:
                    node.right = Node(val)
                else:
                    insert_rec(node.right, val, layer_id + 1)

        insert_rec(self.root, x)

    def get_hash(self):
        hash_arr = []
        def dfs(node):
            if node.left is not None:
                hash_arr.append('L')
                dfs(node.left)
            if node.right is not None:
                hash_arr.append('R')
                dfs(node.right)
            hash_arr.append('U')
        dfs(self.root)
        hash_arr.pop()
        return "".join(hash_arr)


def get_hash(a):
    b = BinaryTree()
    for x in a:
        b.insert(x)
    return b.get_hash()

n,k=map(int,input().split())
seen = set()
for i in range(n):
    a = list(map(int,input().split()))
    hash = get_hash(a)
    seen.add(hash)

print(len(seen))
