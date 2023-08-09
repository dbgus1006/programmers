#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> node;
static int arr[10] = { 0, };
static queue<node> q;

int solution(vector<int> priorities, int location) {

    for (int i = 0; i < priorities.size(); i++)
    {
        q.push(node(priorities[i], i));
        for (int j = 1; j < priorities[i]; j++)
        {
            arr[j]++;
        }
    }

    int answer = 0;

    while (!q.empty())
    {
        node now = q.front();
        q.pop();

        if (arr[now.first] == 0)
        {
            answer++;
            if (location == now.second)
            {
                break;
            }

            for (int i = 1; i < now.first; i++)
            {
                arr[i]--;
            }
        }
        else
        {
            q.push(now);
        }

    }

    return answer;
}