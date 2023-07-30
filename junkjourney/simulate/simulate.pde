import java.util.*;

final int W = 60;

float tile_sz;

int ox = 10;
int oy = 10;

int xs = 1;
int ys = 1;

int xt = 4;
int yt = 4;

HashMap<Integer, HashSet<Integer>> carts;
int n_carts;

String[] instructions;

boolean has_cart(int x, int y) {
  HashSet<Integer> at = carts.get(x);
  if (at == null)return false;
  
  return at.contains(y);
}

void add_cart(int x, int y) {
  if (x == xt && y == yt)return;
  
  if (carts.get(x) == null)carts.put(x, new HashSet<>());
  carts.get(x).add(y);
  n_carts += 1;
}

void del_cart(int x, int y) {
  if (!has_cart(x,y))return;
  carts.get(x).remove(y);
  n_carts -= 1;
}

void setup() {
  size(800, 600);
  
  tile_sz = height/(float)W;
  
  carts = new HashMap<>();
  
  n_carts = 0;
  for (int i = 0; i <= 30; ++i) {
    for (int j = 0; j < 30; ++j) {
      if (i == xs && j== ys)continue;
      add_cart(i,j);
    }
  }
  
  
  instructions = loadStrings("out02");
}



void rectAt(int x, int y) {
  rect(tile_sz*(x+ox), tile_sz*(y+oy), tile_sz,tile_sz);
}

int i_ptr = 0;
void draw() {
  background(255);
  strokeWeight(0.02);
  noFill();
  stroke(0);
  for (int i = 0; i < W; ++i) {
    for (int j = 0; j < W; ++j) {
      rect(i*tile_sz,j*tile_sz,tile_sz,tile_sz);
    }
  }
  
  noFill();
  stroke(0,0,255);
  strokeWeight(1.1);
  rect(ox*tile_sz,oy*tile_sz,31*tile_sz,31*tile_sz);
  
  strokeWeight(0.02);
  stroke(0);
  fill(0,255,0);
  rectAt(xs,ys);
  fill(255,0,0);
  rectAt(xt,yt);
  
  fill(0);
  carts.forEach((x,hset) -> hset.forEach((y) -> rectAt(x,y)));
  
  if (i_ptr < instructions.length) {
    String s = instructions[i_ptr];
    if (s.equals("left"))move(-1,0);
    if (s.equals("right"))move(1,0);
    if (s.equals("up"))move(0,1);
    if (s.equals("down"))move(0,-1);
    i_ptr += 1;
  }
  
  delay(10);
}

void move(int dx, int dy) {
  xs += dx;
  ys += dy;
  
  int x = xs;
  int y = ys;
  
  while (has_cart(x,y)) {
    x += dx;
    y += dy;
  }
  
  add_cart(x,y);
  del_cart(xs,ys);
  
  println(n_carts);
}

void keyReleased() {
  switch(keyCode) {
    case 37:
      move(-1,0);
      break;
    case 38:
      move(0,-1);
      break;
    case 39:
      move(1,0);
      break;
    case 40:
      move(0,1);
      break;
    
  }
}
