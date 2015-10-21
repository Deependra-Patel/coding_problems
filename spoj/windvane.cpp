#include <iostream>
#include <map>
using namespace std;

int m, n;
char **mat;
map<char, int> charMap;
struct node{
	bool leaf;
	int offset;
	int bx, by, tx, ty;
	node *tl, *tr, *bl, *br;
	node(){}
	node(int bx, int by, int tx, int ty){
		this->bx = bx;
		this->by = by;
		this->tx = tx;
		this->ty = ty;
	}
	void update(int x1, int y1, int x2, int y2, int d){
		if(x1>tx || x2<bx || y1>ty || y2<by){
			return;
		}
		if(x1<=bx && y1<=by && tx<=x2 && ty<=y2){
			offset += d;
			return;
		}
		if(tl != NULL)
			tl->update(x1, y1, x2, y2, d);
		if(tr != NULL)
			tr->update(x1, y1, x2, y2, d);
		if(bl != NULL)
			bl->update(x1, y1, x2, y2, d);
		if(br != NULL)
			br->update(x1, y1, x2, y2, d);
	}
	int determine(int x, int y){
		if(x>tx || x<bx || y>ty || y<by){
			return 0;
		}
		if(leaf){
			return offset;
		}
		int temp = 0;
		if(tl != NULL)
			temp += tl->determine(x, y);
		if(tr != NULL)
			temp += tr->determine(x, y);
		if(bl != NULL)
			temp += bl->determine(x, y);
		if(br != NULL)
			temp += br->determine(x, y);
		return temp+offset;
	}

	void print(){
		cout<<leaf<<" "<<offset<<" bx:"<<bx<<",by:"<<by<<",tx:"<<tx<<",ty:"<<ty<<endl;
		
		if(bl!=NULL)bl->print();
		if(tl!=NULL)tl->print();
		if(tr!=NULL)tr->print();
		if(br!=NULL)br->print();
	}
};

node* createTree(int bx, int by, int tx, int ty){
	if(bx>tx || by>ty)
		return NULL;
	node * cur = new node(bx, by, tx, ty);
	//	cout<<" bx:"<<bx<<",by:"<<by<<",tx:"<<tx<<",ty:"<<ty<<endl;
	if(bx == tx && ty == by){
		cur->leaf = true;
		//cout<<bx<<by;
		cur->offset = charMap[mat[m-by-1][bx]];
		cur->tl = cur->bl = cur->tr = cur->br = NULL;
	}
	else {
		cur->offset = 0;
		int centx = (bx+tx)/2;
		int centy = (by+ty)/2;
		cur->bl = createTree(bx, by, centx, centy);
		cur->tl = createTree(bx, centy+1, centx, ty);
		cur->tr = createTree(centx+1, centy+1, tx, ty);
		cur->br = createTree(centx+1, by, tx, centy);
	}
	return cur;
}

int main(){
	charMap['N'] = 0;
	charMap['E'] = 1;
	charMap['S'] = 2;
	charMap['W'] = 3;
	cin>>m>>n;
	mat = new char*[m];
	for(int i=0; i<m; i++){
		mat[i] = new char[n];
		for(int j=0; j<n; j++){
			cin>>mat[i][j];
		}
	}
	node* root = createTree(0, 0, n-1, m-1);
	//	root->print();
	int nt;
	cin>>nt;
	char arr[] = {'N', 'E', 'S', 'W'};
	/*	for(int i=m-1; i>=0; i--){
		for(int j=0;  j<n; j++){
			int temp = root->determine(j, i)%4;
			if(temp<0)
				temp += 4;
			cout<<arr[temp];
		}
		cout<<endl;
		}*/
	while(nt--){
		char com;
		cin>>com;
		if(com == 'C'){
			int x1, x2, y1, y2, temp;
			cin>>x1>>y1>>x2>>y2>>temp;
			if(temp == 0)
				temp = 1;
			else temp = -1;
			//			cout<<y2-1<<m-x2<<y1-1<<m-x1<<temp<<endl;
			int nx1, nx2, ny1, ny2;
			nx1 = y2-1;
			nx2 = y1-1;
			ny1 = m-x2;
			ny2 = m-x1;
			if(nx1>nx2){
				int temp;
   				temp = nx1;
				nx1 = nx2;
				nx2 = temp;
			}
			//cout<<nx1<<ny1<<nx2<<ny2<<endl;
			root->update(nx1, ny1, nx2, ny2, temp);
			/*for(int i=m-1; i>=0; i--){
				for(int j=0;  j<n; j++){
					int temp = root->determine(j, i)%4;
					if(temp<0)
						temp += 4;
					cout<<arr[temp];
				}
				cout<<endl;
				}*/
		}
		else {
			int x, y;
			cin>>x>>y;
			int temp = root->determine(y-1, m-x);
			temp = temp%4;
			//cout<<temp;
			if(temp<0)
				temp += 4;
			cout<<arr[temp]<<endl;
		}
	}
}
