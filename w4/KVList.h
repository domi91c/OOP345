#include <iostream>

using namespace std;
template<typename K, typename V, int N>
class KVList
{
    K m_k[N];
    V m_v[N];
    int m_count;

public:
    KVList()
    {}

    size_t size() const
    {
        return m_count;
    }

    const K &key(int i) const
    {
        return m_k[i];
    }

    const V &value(int i) const
    {
        return m_v[i];
    }

    KVList &add(const K &k, const V &v)
    {
        if (m_count < N) {
            m_k[m_count] = k;
            m_v[m_count] = v;
            m_count++;
        }

        return *this;
    }

    int find(const K &k) const
    {
        for (int i = 0; i < m_count; i++) {
            if (k == m_k[i])
                return i;
        }

        return 0;
    }

    KVList &replace(int i, const K &k, const V &v)
    {
        if (i < m_count) {
            m_k[i] = k;
            m_v[i] = v;
        }


        return *this;
    }
};
