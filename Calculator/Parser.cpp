#include <vector>
#include <string>

class Parser
{
    public:
        std::vector<std::string> parse(std::string in)
        {
            std::vector<std::string> v;

            char curr = ' ', prev = ' ';
            int prevDigitIndex = 0;

            for(int i = 0, j = 0; i < in.length(); i++, j++)
            {
                curr = in[i];
        
                if(curr!=' ')
                {
                    if( ( (curr-'0'>=0 && curr-'0'<=9) || curr=='.') && v.size()>0 && ( (prev-'0'>=0 && prev-'0'<=9) || prev=='.') )
                    {
                        v[prevDigitIndex] += curr; 
                        j--;
                    }
                    else
                    {
                        v.push_back(std::string(1, curr));
                        prevDigitIndex = j;
                    }
                }
                else j--;
        
                prev = curr;
            }
            return v;
        }
};