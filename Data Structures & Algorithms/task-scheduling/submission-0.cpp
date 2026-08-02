class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        // This shall store freq of tasks as tasks are denomianted in form of character 

        unordered_map<char, int > freq;
        for(char t: tasks) freq[t]++;

        //Now we shall make a maxHeap which shall store the fequencies denominatig the tasks 

        priority_queue<int> maxHeap;
        for(auto& [ch, f] : freq) maxHeap.push(f);

        //Now we shall make a queue which shall store the tasks which are in cooldown
        queue<pair<int, int>> q;

        int time = 0;

        while(!maxHeap.empty() || !q.empty()){
            time++;

            //First check if queue is empty or not and if it has a cooldown task available at time<= currentTime

            if(!q.empty() && q.front().second <= time){
                maxHeap.push(q.front().first);
                q.pop();
            }

            //schedule the most frequent avaialble task
            if(!maxHeap.empty()){
                int f = maxHeap.top();
                maxHeap.pop();
                f--;

                //If the task's frequency still prevails add it in queue accordingly
                if(f>0){
                    q.push({f, time+n+1});
                }
            }
        }

        return time;
    }
};
