#include <bits/stdc++.h>
using namespace std;

class magicCube {
    public:
        // dibuat public karena siapa tau di algoritma tertentu perlu tau state nya buat diobrak abrik
        vector<int> state;
        int value;

        magicCube(){
            for (int i = 1; i <= 125; i++) this->state.push_back(i);
            // janlup dirandom ygy
            random_shuffle(state.begin(), state.end());
            this->value = this->countValue();
        }

        magicCube(vector<int> state) {
            this->state = state;
            this->value = this->countValue();
        }

        vector<int> makeNeighborState(int num1, int num2) {
            vector<int> neighborState = this->state;
            int temp = neighborState[num1];
            neighborState[num1] = neighborState[num2];
            neighborState[num2] = temp;
            return neighborState;
        }

        vector<int> makeRandomNeighborState() {
            int num1 = rand() % 124;
            int num2 = rand() % 124;
            while (num1 == num2) num2 = rand() % 124;
            return (this->makeNeighborState(num1, num2));
        }

        void switchStates(vector<int> newState) {
            this->state.swap(newState);
            this->value = this->countValue();
        }

        int countValue(){
            int count = 0;

            // bidang XY
            for (int z = 0; z < 5; z++) {
                for (int y = 0; y < 5; y++) {
                    int row_sum = 0;
                    int col_sum = 0;
                    for (int x = 0; x < 5; x++) {
                        row_sum += state[z * 5 * 5 + y * 5 + x];
                        col_sum += state[z * 5 * 5 + x * 5 + y]; 
                    }
                    if (row_sum == 315) count++;
                    if (col_sum == 315) count++;
                }
            }

            // bidang XZ
            for (int y = 0; y < 5; y++) {
                for (int x = 0; x < 5; x++) {
                    int row_sum = 0;
                    int col_sum = 0;
                    for (int z = 0; z < 5; z++) {
                        row_sum += state[z * 5 * 5 + y * 5 + x];
                        col_sum += state[x * 5 * 5 + y * 5 + z];
                    }
                    if (row_sum == 315) count++;
                    if (col_sum == 315) count++;
                } 
            }

            // bidang YZ
            for (int x = 0; x < 5; x++) {
                for (int z = 0; z < 5; z++) {
                    int row_sum = 0;
                    int col_sum = 0;
                    for (int y = 0; y < 5; y++) {
                        row_sum += state[z * 5 * 5 + y * 5 + x]; 
                        col_sum += state[x * 5 * 5 + z * 5 + y]; 
                    }
                    if (row_sum == 315) count++;
                    if (col_sum == 315) count++;
                }
            }

            // diag XY
            for (int z = 0; z < 5; z++) {
                int diag1_sum = 0;
                int diag2_sum = 0;
                for (int i = 0; i < 5; i++) {
                    diag1_sum += state[z * 5 * 5 + i * 5 + i];           
                    diag2_sum += state[z * 5 * 5 + i * 5 + (5 - 1 - i)]; 
                }
                if (diag1_sum == 315) count++;
                if (diag2_sum == 315) count++;
            }

            // diag XZ
            for (int y = 0; y < 5; y++) {
                int diag1_sum = 0;
                int diag2_sum = 0;
                for (int i = 0; i < 5; i++) {
                    diag1_sum += state[i * 5 * 5 + y * 5 + i];           
                    diag2_sum += state[(5 - 1 - i) * 5 * 5 + y * 5 + i]; 
                }
                if (diag1_sum == 315) count++;
                if (diag2_sum == 315) count++;
            }

            // diag YZ
            for (int x = 0; x < 5; x++) {
                int diag1_sum = 0;
                int diag2_sum = 0;
                for (int i = 0; i < 5; i++) {
                    diag1_sum += state[i * 5 * 5 + i * 5 + x];           
                    diag2_sum += state[(5 - 1 - i) * 5 * 5 + i * 5 + x]; 
                }
                if (diag1_sum == 315) count++;
                if (diag2_sum == 315) count++;
            }

            // 3d diag
            int diag3D1 = 0, diag3D2 = 0, diag3D3 = 0, diag3D4 = 0;
            for (int i = 0; i < 5; i++) {
                diag3D1 += state[i * 5 * 5 + i * 5 + i];                  // (0,0,0) to (4,4,4)
                diag3D2 += state[i * 5 * 5 + i * 5 + (5 - 1 - i)];        // (0,0,4) to (4,4,0)
                diag3D3 += state[i * 5 * 5 + (5 - 1 - i) * 5 + i];        // (0,4,0) to (4,0,4)
                diag3D4 += state[(5 - 1 - i) * 5 * 5 + i * 5 + i];        // (4,0,0) to (0,4,4)
            }
            if (diag3D1 == 315) count++;
            if (diag3D2 == 315) count++;
            if (diag3D3 == 315) count++;
            if (diag3D4 == 315) count++;

            return count;
        }

        
        void printCube(){
            cout << endl <<
            "        " << setw(3) << setfill('0') << state[0] << "-------------------" << setw(3) << setfill('0') << state[1] << "-------------------" << setw(3) << setfill('0') << state[2] << "-------------------" << setw(3) << setfill('0') << state[3] << "------------------" << setw(3) << setfill('0') << state[4] << endl <<
            "       /|                    /|                    /|                    /|                    /|\n" << 
            "      " << setw(3) << setfill('0') << state[5] << "-------------------" << setw(3) << setfill('0') << state[6] << "-------------------" << setw(3) << setfill('0') << state[7] << "-------------------" << setw(3) << setfill('0') << state[8] << "------------------" << setw(3) << setfill('0') << state[9] << "|\n" << 
            "     /  |                  /  |                  /  |                  /  |                  /| |\n" <<
            "    " << setw(3) << setfill('0') << state[10] << "-------------------" << setw(3) << setfill('0') << state[11] << "-------------------" << setw(3) << setfill('0') << state[12] << "-------------------" << setw(3) << setfill('0') << state[13] << "------------------" << setw(3) << setfill('0') << state[14] << "| |\n" <<
            "   /    |                /    |                /    |                /    |                /| | |\n" <<
            "  " << setw(3) << setfill('0') << state[15] << "-------------------" << setw(3) << setfill('0') << state[16] << "-------------------" << setw(3) << setfill('0') << state[17] << "-------------------" << setw(3) << setfill('0') << state[18] << "------------------" << setw(3) << setfill('0') << state[19] << "| | |\n" <<
            " /      |              /      |              /      |              /      |              /| | | |\n" <<
            setw(3) << setfill('0') << state[20] << "-------------------" << setw(3) << setfill('0') << state[21] << "-------------------" << setw(3) << setfill('0') << state[22] << "-------------------" << setw(3) << setfill('0') << state[23] << "------------------" << setw(3) << setfill('0') << state[24] << "| | | |\n" <<
            "|       |             |       |             |       |             |       |             | | | | |\n" <<
            "|       " << setw(3) << setfill('0') << state[25] << "-----------|-------" << setw(3) << setfill('0') << state[26] << "-----------|-------" << setw(3) << setfill('0') << state[27] << "-----------|-------" << setw(3) << setfill('0') << state[28] << "-----------|-|-|-|" << setw(3) << setfill('0') << state[29] << endl <<
            "|      /|             |      /|             |      /|             |      /|             | | | |/|\n" <<
            "|     " << setw(3) << setfill('0') << state[30] << "-------------|-----" << setw(3) << setfill('0') << state[31] << "-------------|-----" << setw(3) << setfill('0') << state[32] << "-------------|-----" << setw(3) << setfill('0') << state[33] << "-------------|-|-|" << setw(3) << setfill('0') << state[34] << "|\n" <<
            "|    /  |             |    /  |             |    /  |             |    /  |             | | |/| |\n" <<
            "|   " << setw(3) << setfill('0') << state[35] << "---------------|---" << setw(3) << setfill('0') << state[36] << "---------------|---" << setw(3) << setfill('0') << state[37] << "---------------|---" << setw(3) << setfill('0') << state[38] << "---------------|-|" << setw(3) << setfill('0') << state[39] << "| |\n" <<
            "|  /    |             |  /    |             |  /    |             |  /    |             | |/| | |\n" <<
            "| " << setw(3) << setfill('0') << state[40] << "-----------------|-" << setw(3) << setfill('0') << state[41] << "-----------------|-" << setw(3) << setfill('0') << state[42] << "-----------------|-" << setw(3) << setfill('0') << state[43] << "-----------------|" << setw(3) << setfill('0') << state[44] << "| | |\n" <<
            "|/      |             |/      |             |/      |             |/      |             |/| | | |\n" <<
            setw(3) << setfill('0') << state[45] << "-------------------" << setw(3) << setfill('0') << state[46] << "-------------------" << setw(3) << setfill('0') << state[47] << "-------------------" << setw(3) << setfill('0') << state[48] << "------------------" << setw(3) << setfill('0') << state[49] << "| | | |\n" <<
            "|       |             |       |             |       |             |       |             | | | | |\n" <<
            "|       " << setw(3) << setfill('0') << state[50] << "-----------|-------" << setw(3) << setfill('0') << state[51] << "-----------|-------" << setw(3) << setfill('0') << state[52] << "-----------|-------" << setw(3) << setfill('0') << state[53] << "-----------|-|-|-|" << setw(3) << setfill('0') << state[54] << endl <<
            "|      /|             |      /|             |      /|             |      /|             | | | |/|\n" <<
            "|     " << setw(3) << setfill('0') << state[55] << "-------------|-----" << setw(3) << setfill('0') << state[56] << "-------------|-----" << setw(3) << setfill('0') << state[57] << "-------------|-----" << setw(3) << setfill('0') << state[58] << "-------------|-|-|" << setw(3) << setfill('0') << state[59] << "|\n" <<
            "|    /  |             |    /  |             |    /  |             |    /  |             | | |/| |\n" <<
            "|   " << setw(3) << setfill('0') << state[60] << "---------------|---" << setw(3) << setfill('0') << state[61] << "---------------|---" << setw(3) << setfill('0') << state[62] << "---------------|---" << setw(3) << setfill('0') << state[63] << "---------------|-|" << setw(3) << setfill('0') << state[64] << "| |\n" <<
            "|  /    |             |  /    |             |  /    |             |  /    |             | |/| | |\n" <<
            "| " << setw(3) << setfill('0') << state[65] << "-----------------|-" << setw(3) << setfill('0') << state[66] << "-----------------|-" << setw(3) << setfill('0') << state[67] << "-----------------|-" << setw(3) << setfill('0') << state[68] << "-----------------|" << setw(3) << setfill('0') << state[69] << "| | |\n" <<
            "|/      |             |/      |             |/      |             |/      |             |/| | | |\n" <<
            setw(3) << setfill('0') << state[70] << "-------------------" << setw(3) << setfill('0') << state[71] << "-------------------" << setw(3) << setfill('0') << state[72] << "-------------------" << setw(3) << setfill('0') << state[73] << "------------------" << setw(3) << setfill('0') << state[74] << "| | | |\n" <<
            "|       |             |       |             |       |             |       |             | | | | |\n" <<
            "|       " << setw(3) << setfill('0') << state[75] << "-----------|-------" << setw(3) << setfill('0') << state[76] << "-----------|-------" << setw(3) << setfill('0') << state[77] << "-----------|-------" << setw(3) << setfill('0') << state[78] << "-----------|-|-|-|" << setw(3) << setfill('0') << state[79] << endl <<
            "|      /|             |      /|             |      /|             |      /|             | | | |/|\n" <<
            "|     " << setw(3) << setfill('0') << state[80] << "-------------|-----" << setw(3) << setfill('0') << state[81] << "-------------|-----" << setw(3) << setfill('0') << state[82] << "-------------|-----" << setw(3) << setfill('0') << state[83] << "-------------|-|-|" << setw(3) << setfill('0') << state[84] << "|\n" <<
            "|    /  |             |    /  |             |    /  |             |    /  |             | | |/| |\n" <<
            "|   " << setw(3) << setfill('0') << state[85] << "---------------|---" << setw(3) << setfill('0') << state[86] << "---------------|---" << setw(3) << setfill('0') << state[87] << "---------------|---" << setw(3) << setfill('0') << state[88] << "---------------|-|" << setw(3) << setfill('0') << state[89] << "| |\n" <<
            "|  /    |             |  /    |             |  /    |             |  /    |             | |/| | |\n" <<
            "| " << setw(3) << setfill('0') << state[90] << "-----------------|-" << setw(3) << setfill('0') << state[91] << "-----------------|-" << setw(3) << setfill('0') << state[92] << "-----------------|-" << setw(3) << setfill('0') << state[93] << "-----------------|" << setw(3) << setfill('0') << state[94] << "| | |\n" <<
            "|/      |             |/      |             |/      |             |/      |             |/| | | |\n" <<
            setw(3) << setfill('0') << state[95] << "-------------------" << setw(3) << setfill('0') << state[96] << "-------------------" << setw(3) << setfill('0') << state[97] << "-------------------" << setw(3) << setfill('0') << state[98] << "------------------" << setw(3) << setfill('0') << state[99] << "| | | |\n" <<
            "|       |             |       |             |       |             |       |             | | | | |\n" <<
            "|       " << setw(3) << setfill('0') << state[100] << "-----------|-------" << setw(3) << setfill('0') << state[101] << "-----------|-------" << setw(3) << setfill('0') << state[102] << "-----------|-------" << setw(3) << setfill('0') << state[103] << "-----------|-|-|-|" << setw(3) << setfill('0') << state[104] << endl <<
            "|      /              |      /              |      /              |      /              | | | |/ \n" <<
            "|     " << setw(3) << setfill('0') << state[105] << "-------------|-----" << setw(3) << setfill('0') << state[106] << "-------------|-----" << setw(3) << setfill('0') << state[107] << "-------------|-----" << setw(3) << setfill('0') << state[108] << "-------------|-|-|" << setw(3) << setfill('0') << state[109] << endl <<
            "|    /                |    /                |    /                |    /                | | |/   \n" <<
            "|   " << setw(3) << setfill('0') << state[110] << "---------------|---" << setw(3) << setfill('0') << state[111] << "---------------|---" << setw(3) << setfill('0') << state[112] << "---------------|---" << setw(3) << setfill('0') << state[113] << "---------------|-|" << setw(3) << setfill('0') << state[114] << endl <<
            "|  /                  |  /                  |  /                  |  /                  | |/     \n" <<
            "| " << setw(3) << setfill('0') << state[115] << "-----------------|-" << setw(3) << setfill('0') << state[116] << "-----------------|-" << setw(3) << setfill('0') << state[117] << "-----------------|-" << setw(3) << setfill('0') << state[118] << "-----------------|" << setw(3) << setfill('0') << state[119] << endl <<
            "|/                    |/                    |/                    |/                    |/       \n" <<
            setw(3) << setfill('0') << state[120] << "-------------------" << setw(3) << setfill('0') << state[121] << "-------------------" << setw(3) << setfill('0') << state[122] << "-------------------" << setw(3) << setfill('0') << state[123] << "------------------" << setw(3) << setfill('0') << state[124] << endl;
        }
};