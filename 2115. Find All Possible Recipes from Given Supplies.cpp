//Link- https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/?envType=daily-question&envId=2025-03-21

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_set<string> availableSupplies;
        unordered_map<string, int> recipeToIndex;
        unordered_map<string, vector<string>> dependencyGraph;

        for (string& supply : supplies) {
            availableSupplies.insert(supply);
        }

        for (int idx = 0; idx < recipes.size(); idx++) {
            recipeToIndex[recipes[idx]] = idx;
        }

        vector<int> inDegree(recipes.size(), 0);

        for (int recipeIdx = 0; recipeIdx < recipes.size(); recipeIdx++) {
            for (string& ingredient : ingredients[recipeIdx]) {
                if (!availableSupplies.count(ingredient)) {
                    dependencyGraph[ingredient].push_back(recipes[recipeIdx]);
                    inDegree[recipeIdx]++;
                }
            }
        }

        queue<int> queue;
        for (int recipeIdx = 0; recipeIdx < recipes.size(); recipeIdx++) {
            if (inDegree[recipeIdx] == 0) {
                queue.push(recipeIdx);
            }
        }

                vector<string> createdRecipes;
        while (!queue.empty()) {
            int recipeIdx = queue.front();
            queue.pop();
            string recipe = recipes[recipeIdx];
            createdRecipes.push_back(recipe);

            if (!dependencyGraph.count(recipe)) continue;

            for (string& dependentRecipe : dependencyGraph[recipe]) {
                if (--inDegree[recipeToIndex[dependentRecipe]] == 0) {
                    queue.push(recipeToIndex[dependentRecipe]);
                }
            }
        }

        return createdRecipes;
    }
};
