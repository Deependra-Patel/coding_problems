#include <iostream>
using namespace std;
#include <algorithm>
struct point{
	int x, y;
	void printp(){
		cout<<x<<","<<y<<endl;
	}
};

bool operator <(const point& p1, const point& p2){
	return p1.x<p2.x;
}

bool inside(point s, int l, point p){
	return (s.x <= p.x && s.x+l>=p.x && s.y<= p.y && s.y+l>=p.y);
}

int main(){
	int n, m, l;
	cin>>n>>m>>l;
	point* squares = new point[n];
	point* points = new point[m];
	for(int i=0; i<n; i++){
		cin>>(squares[i].x)>>(squares[i].y);
	}

	for(int i=0; i<m; i++){
		cin>>(points[i].x)>>(points[i].y);
	}
	sort(squares, squares+n);
	sort(points, points+m);
	int maxi = 0;
	int curSq = 0;
	for(int i=0; i<m; i++){
		point cur = points[i];
		int curi = 0;
		int iter = curSq;
		while(true){
			if(iter<n && squares[iter].x+l < cur.x){
				curSq++;
				iter++;
			}
			else if(iter<n && inside(squares[iter], l, cur)){
				iter++;
				curi++;
			}
            else if(iter>=n || squares[iter].x > cur.x)
                break;
			else iter++;
		}
		//cout<<endl;
		maxi = max(maxi, curi);
	}
	cout<<maxi<<endl;
}
