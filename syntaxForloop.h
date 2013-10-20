#ifndef SYNTAX_FOR_H
#define SYNTAX_FOR_H

#define NotFind -1

class syntaxForloop
{
	//for (cndInitialization; cndCondition; cndIncrease) statement;
public:
// 	std::vector<CString> syntaxMain;
	std::vector<CString>::const_iterator itCurCode;
	int LeftBraces;   //左括號
	int RightBraces;  //右括號
	//cnd = cndCondition
	CString cndInitialization;    //
	CString cndCondition;
	CString cndIncrease;

	std::vector<CString>::const_iterator statement;

	BOOL IsHaveElse;

public:
	syntaxForloop(std::vector<CString>::const_iterator& iCode):itCurCode(iCode)
	{
		resolve();
	};

private:
	BOOL checkKey(const CString& sample, const CString& key)
	{
		int indexKey = sample.Find(key);
		return ( indexKey != NotFind) ? TRUE : FALSE;
	}
	
	void setCndInitial(CString str)
	{
		//str = (int i = 0; i < 100; ++i )
		str = str.Left(str.Find(';'));  //(int i = 0
		cndInitialization = str.Mid(str.Find('(')+1); //int i = 0
	};

	void setCndCondition(CString str)
	{
		//str = (int i = 0; i < 100; ++i )
		str = str.Mid(str.Find(';')+1);   // i < 100; ++i )
		str = str.Left(str.Find(';'));    // i < 100
		str.TrimLeft();    //i < 100
		cndCondition = str;
	};

	void setCndIncrease(CString str)
	{
		//str = (int i = 0; i < 100; ++i )
		str = str.Mid(str.Find(';')+1);   // i < 100; ++i )
		str = str.Mid(str.Find(';')+1);   // ++i )
		str = str.Left(str.Find(')'));    // ++i 
		str.TrimLeft();
		str.TrimRight();
		cndCondition = str;    //i < 100
	};

// 	BOOL MutiSatement(std::vector<CString>::iterator itCode)
// 	{
// 		int indexBraces(itCode->Find('{'));
// 		indexSatement = nextline->Find(';');  // -1 -> some number
// 		indexBraces   = nextline->Find('{');  // -1 -> some number
// 		if (indexSatement == -1)
// 		int indexSatement(forInLine.Find(';'));
// 		int indexBraces(forInLine->Find('{'));
// 
// 	}

// 	BOOL singleSatement()

	BOOL IsMutiSatement(std::vector<CString>::iterator itCode)
	{
		int indexBraces(itCurCode->Find('{'));
		
		//MutiLine
		if (indexBraces != NotFind)
			return TRUE;

		int indexSatement;
		if (itCode->Find("for") != -1)
		{
			std::vector<CString>::iterator nextline = itCode;
			CString forInLine; //這一行
			
			forInLine = statement->Mid(itCode->Find("for")+3);  //(int i = 0; i < 100; ++i ) ....;
			forInLine = forInLine.Mid(forInLine.Find('(')+1);      //int i = 0;i < 100; ++i ) ...;
			forInLine = forInLine.Mid(forInLine.Find(')')+1);      // ...;

			indexSatement = forInLine.Find(';');
		}
		else
			indexSatement = itCode->Find(';');
		
		//single Line
		if (indexSatement != NotFind)  //for(); -> o
			return FALSE;
		else
			return IsMutiSatement(itCode++);
	}

	void findStatement()
	{
	}

	BOOL resolve()
	{
		CString subseFor( itCurCode->Mid(itCurCode->Find("for")+3) );        //(int i = 0; i < 100; ++i )
		
		setCndInitial(subseFor);
		setCndCondition(subseFor);
		setCndIncrease(subseFor);

		if (IsMutiSatement())
	}
};

#endif