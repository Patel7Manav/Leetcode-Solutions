class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
       sort(skill.begin(),skill.end());
       int i=0,j=skill.size()-1;
        long long chem=0;
        long long sk=skill[0]+skill[j];
        chem=skill[0]*skill[j];
        i++;
        j--;
        while(i<j)
        {
            if(skill[i]+skill[j]!=sk)
                return -1;
            chem+=skill[i++]*skill[j--];
        }
        return chem;
    }
};