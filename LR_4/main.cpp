#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

template<typename T>
class TrainStack 
{
    private:
        vector<T> data;

    public:
        void push(const T& value) {
            data.push_back(value);
        }

        void pop() {
            if (!empty()) {
                data.pop_back();
            }
        }

        T& top() {
            return data.back();
        }

        bool empty() const {
            return data.empty();
        }
};

class Train
{
    private:
        enum WagonType {
            Wood,
            Steel
        };

        TrainStack<WagonType> _wagons;
        int _WagonCount = 0;

    public:
        void CreateTrain(int wagonCount)
        {
            while (!_wagons.empty()) {
                _wagons.pop();
            }

            _WagonCount = wagonCount;

            for (int i = 0; i < wagonCount; i++)
            {
                int type;
                if (rand()%2 == 0) type = WagonType::Wood;
                else type = WagonType::Steel;
                cout << "Wagon type " << i + 1 << " (0 - wood, 1 - steel): " << type << endl;
                _wagons.push(static_cast<WagonType>(type));
            }
        }

        void SortKnot()
        {
            TrainStack<WagonType> tempStack;
            TrainStack<WagonType> woodTrain;
            TrainStack<WagonType> steelTrain;

         
            while (!_wagons.empty()) {
                tempStack.push(_wagons.top());
                _wagons.pop();
            }

            while (!tempStack.empty()) {
                WagonType wagon = tempStack.top();
                tempStack.pop();
                
                if (wagon == WagonType::Wood) {
                    woodTrain.push(wagon);
                } else {
                    steelTrain.push(wagon);
                }
            }

            cout << "\n\n\nWood train";
            TrainStack<WagonType> tempWood = woodTrain;
            while (!tempWood.empty()) {
                cout << " - " << (tempWood.top() == WagonType::Wood ? "Wood" : "Steel");
                tempWood.pop();
            }
            
            cout << "\n\n\nSteel train";
            TrainStack<WagonType> tempSteel = steelTrain;
            while (!tempSteel.empty()) {
                cout << " - " << (tempSteel.top() == WagonType::Wood ? "Wood" : "Steel");
                tempSteel.pop();
            }
            cout << endl;
        }

        void PrintTrain()
        {   
            cout << "\n\n\n==================== TRAIN DATA ===============" << endl;
            cout << "Train";
            
            TrainStack<WagonType> tempStack = _wagons;
            vector<WagonType> tempVec;
            
            while (!tempStack.empty()) {
                tempVec.push_back(tempStack.top());
                tempStack.pop();
            }
            
            for (int i = tempVec.size() - 1; i >= 0; i--)
            {
                if (tempVec[i] == WagonType::Steel) cout << " - " << "Steel"; 
                else cout << " - " << "Wood"; 
            }
        }
};

int main()
{
    srand(time(NULL));
    Train train;

    int WagonNum;
    cout << "Enter the number of wagons: ";
    cin >> WagonNum;

    train.CreateTrain(WagonNum);

    train.PrintTrain();

    train.SortKnot();

    printf("\n\n========================================================\n\n");

    main();

    return 0;
}