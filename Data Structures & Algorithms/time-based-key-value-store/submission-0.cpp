class TimeMap {
private :
    unordered_map<string, vector<pair<int, string>>> store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(store.find(key) == store.end()) return "";

        auto& history = store[key];

        int left = 0;
        int right = history.size()-1;
        string res = "";

        while(left<=right){
            int mid = left + (right-left)/2;

            if(history[mid].first<=timestamp){
                res = history[mid].second;
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }

        return res;
    }
};
