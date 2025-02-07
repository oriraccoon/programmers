#include <string>
#include <vector>
using namespace std;

int minSteps = 1e9;  // 매우 큰 값으로 초기화

// 단어가 한 글자만 다른지 확인하는 함수
bool isOneLetterDifferent(const string& word1, const string& word2) {
    int differenceCount = 0;
    for (size_t i = 0; i < word1.size(); ++i) {
        if (word1[i] != word2[i]) {
            ++differenceCount;
            if (differenceCount > 1) return false;
        }
    }
    return differenceCount == 1;
}

// DFS 함수
void dfs(vector<string>& words, vector<bool>& visited, string currentWord, string target, int steps) {
    if (currentWord == target) {
        if (steps < minSteps) minSteps = steps;  // 최소값 업데이트
        return;
    }

    for (size_t i = 0; i < words.size(); ++i) {
        if (!visited[i] && isOneLetterDifferent(currentWord, words[i])) {
            visited[i] = true;
            dfs(words, visited, words[i], target, steps + 1);
            visited[i] = false;  // 백트래킹
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    // target이 words에 없는 경우
    bool targetExists = false;
    for (const string& word : words) {
        if (word == target) {
            targetExists = true;
            break;
        }
    }
    if (!targetExists) return 0;

    vector<bool> visited(words.size(), false);
    dfs(words, visited, begin, target, 0);

    return (minSteps == 1e9) ? 0 : minSteps;
}
