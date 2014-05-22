#include <iostream>
#include <vector>
using namespace std;
class Chooser{
public: int numSets(vector<int> easy, vector<int> middle, vector<int> hard){
	int ans=0;
	for (int i=0; i<easy.size(); i++){
		if(!(easy[i]>=5 && easy[i]<=15))
			continue;
		for(int j=0; j<middle.size(); j++){
			if(!(middle[j]>=15 && middle[j]<=45))
				continue;
			for(int k=0; k<hard.size(); k++){
				if(!(hard[k]>=30 && hard[k]<=55))
					continue;
				if(easy[i]+middle[j]+hard[k]>=60 && easy[i]+middle[j]+hard[k]<=75)
					ans++;
			}
		}
	}
	return ans;
}
};