#include "pch.h"
#include "CppUnitTest.h"
#include "../PDS_7/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
	TEST_CLASS(UnitTest1) {
	public:
        TEST_METHOD(TestCreateAdjacencyMatrix) {
            int n = 3, m = 3;
            int** edges = new int* [m];
            edges[0] = new int[2] {1, 2};
            edges[1] = new int[2] {2, 3};
            edges[2] = new int[2] {3, 1};

            int** adjacencyMatrix = createAdjacencyMatrix(n, m, edges);

            Assert::AreEqual(1, adjacencyMatrix[0][1]);  // 1->2
            Assert::AreEqual(0, adjacencyMatrix[0][2]);  // 1->3
            Assert::AreEqual(1, adjacencyMatrix[1][2]);  // 2->3
            Assert::AreEqual(1, adjacencyMatrix[2][0]);  // 3->1

            for (int i = 0; i < n; ++i)
                delete[] adjacencyMatrix[i];

            delete[] adjacencyMatrix;

            for (int i = 0; i < m; ++i)
                delete[] edges[i];

            delete[] edges;
        }
	};
}
