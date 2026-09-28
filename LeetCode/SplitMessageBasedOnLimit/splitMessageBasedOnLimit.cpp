class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        int n=message.size();

        for(int b=1;b<=n;b++){
            int db=to_string(b).size();
            long long cap=0;
            int p=1;

            while(p<=b){
                int r=min(b,p*10-1);
                int cnt=r-p+1;
                int di=to_string(p).size();
                int take=limit-di-db-3;

                if(take<=0){
                    cap=-1;
                    break;
                }

                cap+=1LL*cnt*take;
                p*=10;
            }

            if(cap<n) continue;

            vector<string> ans;
            int pos=0;

            for(int i=1;i<=b;i++){
                string suffix="<"+to_string(i)+"/"+to_string(b)+">";
                int take=limit-suffix.size();

                if(i==b)
                    take=n-pos;

                ans.push_back(message.substr(pos,take)+suffix);
                pos+=take;
            }

            if(pos==n) return ans;
        }

        return {};
    }
};