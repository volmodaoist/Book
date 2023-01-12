// 其实按照二维上升子序列的做法来写也就可以了，但是数据量增大之后也就无法通过了
#define MAXN 100005
class Solution {
public:
    int seq[MAXN], head = 0, tail = -1;
    
    // 这个函数是用于调试代码的
    void print_seq(vector<vector<int>> &env){
        for(int i = head; i <= tail; i++){
            printf("[%d, %d] ", env[seq[i]][0], env[seq[i]][1]);
        }
        printf("\n");
    }

    // 本题其实就是上升子序列的二维版本，但是数据量比较大，需要使用 O(nlogn)做法才能通过
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end(), [](const vector<int> &a, const vector<int> &b){
           return (a[0] != b[0]) ? (a[0] < b[0]): (a[1] > b[1]);
        });

        int ans = 0;
        for(int i = 0; i < env.size(); i++){
            if(tail < head || env[i][0] > env[seq[tail]][0] && env[i][1] > env[seq[tail]][1]){
                seq[++tail] = i;
            }else{
                int lo = 0, hi = tail, t = env[i][1]; 
                while(lo < hi){
                    int md = (lo + hi) / 2;
                    if(env[seq[md]][1] >= t){
                        hi = md;
                    }else{
                        lo = md + 1;
                    }
                }
                seq[lo] = i;
            }
            // print_seq(env);
        }
        return tail - head + 1;
    }
};