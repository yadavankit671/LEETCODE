#include<bits/stdc++.h>
using namespace std;
// using map and set approach  // !! Scroll down !!
class Solution{
    private : 
    // not exactly max Heap but sorting in descending order
    struct compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            if (a.first != b.first) {
                return a.first > b.first;
            } 
            return a.second < b.second; 
        }
    };
    public : 
    vector<int> rearrangeBarcodes(vector<int>& barcodes){
        unordered_map<int,int> mp;
        for(int x : barcodes) mp[x]++;
        set<pair<int, int>, compare> st;
        for(auto itr =mp.begin();itr!=mp.end();++itr){
            st.insert({itr->second,itr->first});
        }
        vector<int> ans;
        while(!st.empty()){
            auto first = *st.begin();
            st.erase(st.begin());
            ans.push_back(first.second);
            auto second = make_pair(INT_MIN,INT_MIN);
            if(!st.empty()){
                second=*st.begin();
                st.erase(st.begin());
                ans.push_back(second.second);
            }
            if(first.first>1) st.insert({first.first-1,first.second});
            if(second.first>1) st.insert({second.first-1,second.second});
        }
        return ans;
    }
};
int main(){
    Solution obj;
    vector<int> barcodes={1,1,1,1,2,2,2,2};
    vector<int> res=obj.rearrangeBarcodes(barcodes);
    cout<<res.size()<<endl;
    for(auto x:res)
    cout<<x<<" ";
    return 0;
}
/*
Max Heap LinkedList

class MaxHeapNode {
public:
    int barcode;
    int frequency;
    MaxHeapNode* next;

    MaxHeapNode(int barcode, int frequency) : barcode(barcode), frequency(frequency), next(nullptr) {}
};

class MaxHeap {
public:
    MaxHeapNode* head;

    MaxHeap() : head(nullptr) {}

    void insert(int barcode, int frequency) {
        MaxHeapNode* newNode = new MaxHeapNode(barcode, frequency);
        if (!head || newNode->frequency > head->frequency) {
            newNode->next = head;
            head = newNode;
        } else {
            MaxHeapNode* current = head;
            while (current->next && current->next->frequency > newNode->frequency) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    MaxHeapNode* extractMax() {
        if (!head) return nullptr;
        MaxHeapNode* maxNode = head;
        head = head->next;
        return maxNode;
    }
};

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> frequencyMap;
        for (int barcode : barcodes) {
            frequencyMap[barcode]++;
        }

        MaxHeap maxHeap;
        for (const auto& pair : frequencyMap) {
            maxHeap.insert(pair.first,pair.second);
        }

        vector<int> result(barcodes.size());
        int index = 0;

        while (maxHeap.head) {
            MaxHeapNode* node1 = maxHeap.extractMax();
            result[index++] = node1->barcode;
            MaxHeapNode* node2 = nullptr;
            if (maxHeap.head) {
                node2 = maxHeap.extractMax();
                result[index++] = node2->barcode;
            }
            
            if (node1->frequency > 1) {
                node1->frequency--;
                maxHeap.insert(node1->barcode, node1->frequency);
            }
            if (node2 && node2->frequency > 1) {
                node2->frequency--;
                maxHeap.insert(node2->barcode, node2->frequency);
            }

            delete node1;
            delete node2;
        }

        return result;
    }
};


*/