#include <iostream>
#include <vector>
using namespace std;

// Depth First Search function to explore rooms
void dfs(int node, vector<vector<int>>& rooms, vector<bool>& visited, int& count) {
    visited[node] = true;
    count++;

    for (int key : rooms[node]) {
        if (!visited[key]) {
            dfs(key, rooms, visited, count);
        }
    }
}

// Function to check if all rooms can be visited
bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<bool> visited(n, false);
    int count = 0;

    dfs(0, rooms, visited, count);

    return count == n;
}

int main() {
    // Input: number of rooms and their keys
    int n;
    cout << "Enter the number of rooms: ";
    cin >> n;

    vector<vector<int>> rooms(n);
    cout << "Enter the keys for each room (end each room's keys with -1):\n";
    for (int i = 0; i < n; i++) {
        cout << "Room " << i << ": ";
        int key;
        while (cin >> key && key != -1) {
            rooms[i].push_back(key);
        }
    }

    // Check if all rooms can be visited
    if (canVisitAllRooms(rooms)) {
        cout << "Yes, all rooms can be visited.\n";
    } else {
        cout << "No, not all rooms can be visited.\n";
    }

    return 0;
}