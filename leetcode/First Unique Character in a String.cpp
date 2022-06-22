class Solution {
public:
    int firstUniqChar(string s) {
        int marcas[200],l;
        for(int i=0;i<s.size();i++){
            l=s[i];
            marcas[l]=0;
        }
        for(int i=0;i<s.size();i++){
            l=s[i];
            //cout<<l<<" ";
            marcas[l]++;
        }
       // cout<<"\n";
        for(int i=0;i<s.size();i++){
            l=s[i];
            //cout<<marcas[l]<<" ";
            if(marcas[l]==1){
                cout<<"\n";
                return i;
            }
        }
        cout<<"\n";
        return -1;
    }
};
