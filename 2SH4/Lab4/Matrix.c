
#include <string>
using namespace std;

class Matrix {

	public:

		// Default Constructor
		Matrix();		

		// Additional Constructors
		Matrix( int row, int col );
		Matrix( int row, int col, int **table );

		//Copr COnstructor for deep copy??
		Matrix( const Matrix &m);

		// Do you think you need a Destructor?  Why or why not?
		~Matrix();
		

		// Getters
		int getElement(int i, int j);
		int getsizeofrows();
		int getsizeofcols();

		// Setters
		bool setElement(int x, int i, int j);

		// Other Member Functions
		Matrix copy();						// Create a Copy of This Matrix
		void addTo( Matrix &m );				// Add Matrix m to this matrix
		Matrix subMatrix(int i, int j);     // Obtain the upper-left submatrix of this matrix
		string toString();					// String Conversion Method


	private:

		// Stack Data Members
		int    rowsNum;
		int    colsNum;

		// Heap Data Members - Do you need to release them?  Where, when, and how?
		int    **matrixData;

};

