#ifndef SYNTAX_FOR_H
#define SYNTAX_FOR_H

#define NotFind -1

class syntaxFor
{
public:
	std::vector<CString> syntaxMain;
	int LeftBraces;
	int RightBraces;
	CString starting;
	CString condition;
	CString stepCount;

	std::vector<CString> Content;
public:
	BOOL checkKey(const CString& sample, const CString& key)
	{
		int indexKey = sample.Find(key);
		return ( indexKey != NotFind) ? TRUE : FALSE;
	}

	void Init()
	{
		for(std::vector<CString>::iterator codeIt = syntaxMain.begin(); codeIt != syntaxMain.end(); ++codeIt)
		{
			if ( checkKey(*codeIt, "for") )  //§ä¨ìfor
			{
				CString backOfFor( codeIt->Mid(codeIt->Find("for")+3) );        //(int i = 0; i < 100; ++i )

				starting = backOfFor.Left(backOfFor.Find(';')).Mid(backOfFor.Find('(')+1);

				condition = backOfFor.Mid(backOfFor.Find(';')+1);               // i < 100; ++i )
				stepCount = condition.Right(condition.Find(';')-1);

				stepCount.Format("%s", stepCount.Left( stepCount.Find(')') ));  //  ++i 				
				condition.Format("%s", condition.Left( condition.Find(';') ));  // i < 100;

// 				AfxMessageBox(starting);
// 				AfxMessageBox(condition);
// 				AfxMessageBox(stepCount);
			}
		}
	}

	syntaxFor(std::vector<CString>::iterator _B, std::vector<CString>::iterator _E)
	{
		syntaxMain.insert(syntaxMain.begin(), _B, _E);
		Init();
	};

protected:
private:
};

#endif