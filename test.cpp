#include <iostream>  
using namespace std;
  
template <typename T, template <typename, typename...> class SetType = set>  
class SetOperations {  
public:  
    using Set = SetType<T>;  
  
    SetOperations(const Set& set) : m_set(set) {}  
  
    Set unionWith(const Set& other) const {  
        Set result = m_set;  
        result.insert(other.begin(), other.end());  
        return result;  
    }  
  
    Set intersectWith(const Set& other) const {  
        Set result;  
        set_intersection(m_set.begin(), m_set.end(),  
                               other.begin(), other.end(),  
                               inserter(result, result.end()));  
        return result;  
    }  
  
    Set differenceWith(const Set& other) const {  
        Set result;  
        set_difference(m_set.begin(), m_set.end(),  
                            other.begin(), other.end(),  
                            inserter(result, result.end()));  
        return result;  
    }  
  
private:  
    Set m_set;  
};  
  
int main() {  
    SetOperations<int> set1({1, 2, 3, 4, 5});  
    SetOperations<int> set2({4, 5, 6, 7, 8});  
  
    auto unionSet = set1.unionWith(set2);  
    for (const auto& elem : unionSet) {  
        cout << elem << " ";  
    }  
    cout << endl;  
   
    auto intersectSet = set1.intersectWith(set2);  
    for (const auto& elem : intersectSet) {  
        cout << elem << " ";  
    }  
    cout << endl;  
  
    auto diffSet = set1.differenceWith(set2);  
    for (const auto& elem : diffSet) {  
        cout << elem << " ";  
    }  
    cout << endl;  
  
    return 0;  
}