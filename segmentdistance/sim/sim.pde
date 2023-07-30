
class Point {
  float x,y;
  public Point(float x, float y) {
    this.x = x;
    this.y = y;
  }
  
  void draw() {
    fill(255);
    ellipse(this.x,this.y,5,5);
  }
  
  float dist(Point other) {
    return (float)sqrt((float)(this.x-other.x)*(this.x-other.x) + (float)(this.y-other.y)*(this.y-other.y));
  }
}

class Segment {
  Point start, end;
  
  public Segment(Point start, Point end) {
    this.start = start;
    this.end = end;
  }
  
  void draw(int r, int g, int b) {
    fill(r,g,b);
    stroke(r,g,b);
    start.draw();
    end.draw();
    line(start.x,start.y,end.x,end.y);
  }
}

Segment[] seg = new Segment[2];
Segment shortest;
int selected = 0;

boolean close(Point a, Point b) {
  return a.dist(b) <= 0.01;
}

Segment approx_shortest(Segment a, Segment b) {
  Point a_ptr = new Point(a.start.x,a.start.y);
  Point b_ptr;
  
  float step = 100.0;
  
  float a_dx = ((float)a.end.x - a.start.x) / step;
  float a_dy = ((float)a.end.y - a.start.y) / step;
  
  
  
  Point ans_a = new Point(a.start.x,a.start.y);
  Point ans_b = new Point(b.start.x,b.start.y);
  
  float ans = ans_a.dist(ans_b);
  
  while (!close(a_ptr, a.end)) {
    //println(a_ptr.x + " " + a_ptr.y + " -> " + a.end.x + " " + a.end.y);
    b_ptr = new Point(b.start.x,b.start.y);
    float b_dx = ((float)b.end.x - (float)b.start.x) / step;
    float b_dy = ((float)b.end.y - (float)b.start.y) / step;
    
    while (!close(b_ptr,b.end)) {
      //println("    " + b_ptr.x + " " + b_ptr.y + " -> " + b.end.x + " " + b.end.y);
      if (a_ptr.dist(b_ptr) < ans) {
        ans_a = new Point(a_ptr.x, a_ptr.y);
        ans_b = new Point(b_ptr.x, b_ptr.y);
        ans = ans_a.dist(ans_b);
      }
      b_ptr.x += b_dx;
      b_ptr.y += b_dy;
    }
    a_ptr.x += a_dx;
    a_ptr.y += a_dy;
  }
  return new Segment(ans_a, ans_b);
}

Point get_selected() {
  int seg_ptr = 0;
  if (selected > 1)seg_ptr = 1;
  
  boolean is_end = (selected%2 == 1);
  
  if (is_end)return seg[seg_ptr].end;
  else return seg[seg_ptr].start;
}

void setup() {
  size(800,600);
  seg[0] = new Segment(new Point(2,2), new Point(2+50,2+50));
  seg[1] = new Segment(new Point(2+100,2+100), new Point(2+150,2+150));
  
  shortest = approx_shortest(seg[0], seg[1]);
}

void draw() {
  background(0);
  for (int i = 0; i < 2; ++i) {
    seg[i].draw(255,255,255);
  }
  
  noFill();
  stroke(0,255,0);
  ellipse(get_selected().x, get_selected().y, 10,10);
  
  shortest.draw(255,0,0);
}

void keyPressed() {
  if (key == 'n') {
    selected += 1;
    selected %= 4;
  } else {
    switch(keyCode) {
      case 37:
        // left
        get_selected().x -= 1.0;
        if (get_selected().x < 0)get_selected().x = 0.0;
        break;
      case 38:
        // up
        get_selected().y -= 1.0;
        if (get_selected().y < 0)get_selected().y = 0.0;
        break;
      case 39:
        // right
        get_selected().x += 1.0;
        if (get_selected().x > width)get_selected().x = width;
        break;
      case 40:
        // down
        get_selected().y += 1.0;
        if (get_selected().y > height)get_selected().y = height;
        break;
    }
    shortest = approx_shortest(seg[0], seg[1]);
  }
}
