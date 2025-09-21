class FoodRatings {
    unordered_map<string, pair<string,int>> foodInfo;
    unordered_map<string, set<pair<int,string>>> cuisineInfo;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodInfo[foods[i]] = {cuisines[i], ratings[i]};
            cuisineInfo[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [cuisine, oldRating] = foodInfo[food];
        cuisineInfo[cuisine].erase({-oldRating, food});
        cuisineInfo[cuisine].insert({-newRating, food});
        foodInfo[food].second = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisineInfo[cuisine].begin()->second;
    }
};