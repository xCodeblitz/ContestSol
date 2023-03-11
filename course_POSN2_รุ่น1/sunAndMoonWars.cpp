#include<bits/stdc++.h>
using namespace  std;
#define ll long long

struct DATA{
    string id;
    string id1;
    string id2;
	int type;      // 0 = Wall, 1 = Catapult, 3 = magiciam
	int K;          // A,D,Z value
};

bool LessKtoMoreK(const DATA& a, const DATA& b){
    // Type :  Catapult -> wall || K : Less to More ||id : Less to More
    if(a.type==b.type && a.K==b.K){
        return a.id < b.id;
    }
    if(a.type==b.type){
        return a.K < b.K;
    }
    return a.type > b.type;
}

bool MoreKtoLessK(const DATA& a, const DATA& b){
    // Type :  wall -> catapult|| K : More to less ||id : Less to More
    if(a.type==b.type && a.K==b.K){
        return a.id < b.id;
    }
    if(a.type==b.type){
        return a.K > b.K;
    }
    return a.type < b.type;
}

bool sortID(const DATA& a, const DATA& b){
    return a.id < b.id;
}

int N,M;
vector<DATA> sun;
vector<DATA> moon;
ll ans1=0, ans2=0;


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    sun.clear(), moon.clear();

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
        struct DATA temp={"9999","9999","9999",0,0};
		cin >> temp.id >>  temp.type >>temp.K;
		sun.push_back(temp);
	}
	for (int i = 0; i < M; i++) {
        struct DATA temp = {"9999","0000","1000",3,0};
		cin >> temp.id >> temp.K;
		moon.push_back(temp);
	}

	// ans 1 : Strong Z attack Weak Catapult
    sort(sun.begin(),sun.end(),LessKtoMoreK);
    sort(moon.begin(),moon.end(),MoreKtoLessK);

	for (int i=0; i<min(N,M); i++) {
        
		if (!sun[i].type){
			break;  // If not a Capult -> break
		}
        if (moon[i].K <= sun[i].K){
			break;  // If Z can't break -> break
		}        

		ans1 += moon[i].K - sun[i].K;
        moon[i].id1 = sun[i].id;
	}

    // Ans 2 : 
	sort(sun.begin(),sun.end(),MoreKtoLessK);
    sort(moon.begin(),moon.end(),LessKtoMoreK);
	bool used[105]={0};
    memset(used,0,sizeof(used));

	for (int i = 0; i < N; i++) {
		bool check = 0;

        // find magicial to destroy it
		for (int j = 0; j < M; j++) {
            if (used[j]) { continue;}

            // Greedy choose weak Z defend strong wall or strong catapult
			if ( moon[j].K > sun[i].K){
				used[j] = true;
                moon[j].id2 = sun[i].id;
				if(sun[i].type) {
					ans2 += moon[j].K - sun[i].K;
				}

				check = true; break; // found magicial to destroy it
			}
		}

		// can't destroy this item -> only answer 1
		if (!check) {
            cout << ans1 << "\n";
            sort(moon.begin(),moon.end(),sortID);
            for(auto x:moon){
                cout << x.id << " " << x.id1 << "\n";
            }
            exit(0);
		}
	}


	// direct damage to town
	for (int i = 0; i < M; i++) {
		if (!used[i]) {
			ans2 += moon[i].K;
		}
	}

    sort(moon.begin(),moon.end(),sortID);
    if(ans1 > ans2){
        cout << ans1 << "\n";
        for(auto x:moon){
            cout << x.id << " " << x.id1 << "\n";
        }
    }else{
        cout << ans2 << "\n";
        for(auto x:moon){
            cout << x.id << " " << x.id2 << "\n";
        }
    }
}