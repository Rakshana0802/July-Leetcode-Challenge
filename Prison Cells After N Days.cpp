class Solution
{
   public:
   vector<int> prisonAfterNDays(vector<int>& cells, int N)
   {
      map <int, vector <int> > m;
      if(N == 0) return cells;
      set <vector <int> > visited;
      visited.insert(cells);
      for(int i = 1; i<=14 ; i++ )
      {
         vector <int> temp(8);
         for(int j = 1; j < 7; j++)
         {
            if(cells[j - 1] ^ cells[j + 1] == 0)
               temp[j] = 1;
         }
         cells = temp;
         m[i] = temp;
         visited.insert(temp);
      }
      return m[N % 14 == 0? 14 : N % 14];
   }
};
