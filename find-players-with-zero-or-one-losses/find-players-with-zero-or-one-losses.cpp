class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> winners;
        unordered_set<int> lostOne;
        unordered_set<int> lostMore;

        for (int i = 0; i < matches.size(); i++) {
            int winner = matches[i][0];
            int loser = matches[i][1];

            if (!lostOne.contains(winner) && !lostMore.contains(winner)) {
                winners.insert(winner);
            }

            if (winners.contains(loser) || (!lostMore.contains(loser) && !lostOne.contains(loser))) {
                winners.erase(loser);
                lostOne.insert(loser);
            }
           else if (lostOne.contains(loser)) {
                lostOne.erase(loser);
                lostMore.insert(loser);
            }
        }

        vector<int> winnerList;
        vector<int> losersList;

        for (const int& element : winners) {
            winnerList.push_back(element);
        }
        for (const int& element : lostOne) {
            losersList.push_back(element);
        }

    sort(winnerList.begin(),winnerList.end());
    sort(losersList.begin(),losersList.end());

    return {winnerList, losersList};
    }
};