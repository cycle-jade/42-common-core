#pragma once 
# include <vector>
# include <deque>
# include <string>

class PmergeMe
{
    private:
        std::vector<int> _vec;
        std::deque<int> _deq;

    void sortVector(std::vector<int>& seq);
    void insertVector(std::vector<int>& main,
                    std::vector<int>& pend,
                    std::vector<int>& pairs);
    void sortDeque(std::deque<int>& seq);
    void insertDeque(std::deque<int>& main,
                    std::deque<int>& pend,
                    std::deque<int>& pairs);
    
    std::vector<int> jacobsthalSequence(int n) const;

    public:

        PmergeMe();
        PmergeMe(PmergeMe const&  other);
        PmergeMe& operator=(PmergeMe const&  other);
        ~PmergeMe();
        
        void addNumber(std::string const& token);
        void sortAndTime();
        void printSequence(std::string const& label, std::vector<int> const& seq) const;
};