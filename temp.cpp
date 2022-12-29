vector<int> v;
vector<int> mn;
vector<int> mx;
void build(int node, int start, int end)
{
    if(start == end)
    {
        
        mn[node] = A[start];
        mx[node] = A[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        
        mx[node] = max(mx[2*node],mx[2*node+1]);
        mn[node] = mix(mn[2*node],mn[2*node+1]);
    }
}

int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        return 0;
    }
    if(l <= start and end <= r)
    {
        
        if(mn[node]>x){
            return end-start+1;
        }
        if(mx[node]<x){
            return 0;
        }

        int mid = (start + end) / 2;
        int p1 = query(2*node, start, mid, l, r);
        int p2 = query(2*node+1, mid+1, end, l, r);
        return (p1 + p2);
    }
    
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}

vector<vector<int>> dummy(int n,vector<int>&l,vector<int>&r){
    vector<vector<int>> ans;
    if(l[0]!=0){
        vector<int> v;
        v.push_back(0);
        v.push_back(l[0]);
    }
    
    for(int i=0;i<n-1;i++){
        vector<int> v;
        if(r[i]<l[i+1]){
            v.push_back(r[i]);
            v.push_back(l[i+1]);
        }
        ans.push_back(v);
    }
    
    if(r[n-1]!=1000000000){
        vector<int> v;
        v.push_back(r[n-1]);
        v.push_back(1000000000);
    }
    
    if(ans.size()==0){
        ans.push_back({-1,-1});
    }
    return ans;
}

struct Job{
    int hr;
    int mn;
    int sc;
    int nt;
};

static bool comp(Job a , Job b){
    if(a.hr!=b.hr){
       return a.hr<b.hr;
    }
    if(a.mn!=b.mn){
        return a.mn<b.mn;
    }
    if(a.sc!=b.sc){
        return a.sc<b.sc;
    }
    return a.nt>=b.nt;
}

int dummy(int n , vector<vector<string>> arr){
    vector<Job> v;
    for(int i=0;i<n;i++){
        for(int j=1;j<3;j++){
            string time = arr[i][j];
            int hrs = stoi(time.substr(0,2));
            int min = stoi(time.substr(3,2));
            int sec = stoi(time.substr(6,2));
            int nat =1;
            if(j==2){
                nat = -1;
            }
            Job j;
            j.hr = hrs;
            j.mn = min;
            j.sc = sec;
            j.nt = nat;
            v.push_back(j);
        }
        
    }
    
    sort(v.begin(),v.end(),comp);
    
    int g_max = 0;
    int ans = 0;
    
    for(int i=0;i<n;i++){
        ans+=v[i].nt;
        g_max=max(g_max,ans);
    }
    return g_max;
}
