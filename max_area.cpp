#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Point {
public:
    int xval;
    int yval;
    
    int distFromCenter;

    Point() {
        
    }
    Point(int x, int y) {
        xval = x;
        yval = y;
    }
};

int distance(Point *p1, Point *p2) {
    int dx = p1->xval - p2->xval;
    int dy = p1->yval - p2->yval;
    
    return dx*dx + dy*dy;
}

bool comp(const Point& lhs, const Point& rhs)
{
  return lhs.distFromCenter < rhs.distFromCenter;
}


int main() {
	int n,k;
	cin>>n;
	
    int avgx = 0, avgy = 0;
	
	Point points[4];
	for(int i=0; i < n; i++) {
	    cin>>points[i].xval;
	    avgx+= points[i].xval;
	}
	avgx = avgx/n;
	
	cin>>n;
	for(int i=0; i < n; i++) {
	    cin>>points[i].yval;
	    avgy+= points[i].yval;
	}
	avgy = avgy/n;
	
	//for(int i=0; i < n; i++) {
	//    cout<<points[i].xval<<","<<points[i].yval<<endl;
	//}
	
	cin>>k;
	//cout<<k<<endl;
	// cout<<"center"<<avgx<<","<<avgy<<endl;
	
	Point center = Point(avgx, avgy);
	
	for(int i=0; i < n; i++) {
	    points[i].distFromCenter = distance(&points[i], &center);
	    //cout<<points[i].xval<<","<<points[i].yval<<":"<<"dist="<<points[i].distFromCenter<<endl;
	}
	
	sort(std::begin(points), std::end(points), comp);
	
	//for(int i=0; i < n; i++) {
	//    cout<<points[i].xval<<","<<points[i].yval<<endl;
	//}
	
	int minx = INT_MAX, miny = INT_MAX, maxx = INT_MIN, maxy =INT_MIN;
	
	//Iterate on first k
	for(int i=0; i < k; i++) {
	    
	    if(minx > points[i].xval) {
	        minx = points[i].xval;
	    }
	    if(maxx < points[i].xval) {
	        maxx = points[i].xval;
	    }
	    
	    if(miny > points[i].yval) {
	        miny = points[i].yval;
	    }
	    if(maxy < points[i].yval) {
	        maxy = points[i].yval;
	    }
	}
	
	int dx = maxx - minx + 2;
	int dy = maxy - miny + 2;
	
	//cout<<"dx2"<<dx*dx<<" dy2"<<dy*dy;
	if(dx*dx > dy*dy) return dx*dx;
	return dy*dy;
}