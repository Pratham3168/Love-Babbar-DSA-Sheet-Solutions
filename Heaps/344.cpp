class Solution {
public:
    string reorganizeString(string s) {
        
        string str_ans = "";
        priority_queue<pair<int,char>> pq;        
        int n = s.length();
        int maxFreq = 0;
        unordered_map<char,int> mp;
        for(int i = 0; i< n ; i++){
            mp[s[i]]++;
            maxFreq = max(maxFreq, mp[s[i]]);
        }
        if (maxFreq > (n + 1) / 2)
            return "";

        for(auto &it: mp){

            char ch = it.first;
            int freq = it.second;
            pq.push({freq,ch});
        }

        while(!pq.empty()){

            if(pq.size() == 1 && pq.top().first > 1){
                return "";
            }
            else if(pq.size() == 1 && pq.top().first == 1){
                str_ans += pq.top().second;
                return str_ans;
            }

            pair<int,char> first_ele = pq.top();
            pq.pop();
            pair<int,char> second_ele = pq.top();
            pq.pop();
            int first_freq = first_ele.first;
            char first_char = first_ele.second;
            int second_freq = second_ele.first;
            char second_char = second_ele.second;
            str_ans = str_ans + first_char + second_char;
            first_freq--;
            second_freq--;
            if(first_freq > 0){
                pq.push({first_freq,first_char});
            }
            if(second_freq > 0){
                pq.push({second_freq,second_char});
            }

        }
        return str_ans;
    }
};