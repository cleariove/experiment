/*字符串分割函数，将产生式右部的候选返回,识别‘|’，从pos位开始分割*/
string strsplit(string strTok, int pos) {
	string str;
	size_t position;
	position = strTok.find("|", pos);
	if (position != string::npos) {			//找到了‘|’
		str = strTok.substr(pos, position - pos);
	}
	else {								//没找到
		str = strTok.substr(pos, strTok.size() - pos);
	}
	return str;
}
/*获得一个文法中尚未定义的非终结符，即特定的大写字母*/
char GetWord(char *p) {
	char ch, word[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
		'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	int w, x;
	for (w = 0; w < 26; w++) {
		ch = word[w];
		for (x = 0; x < m; x++) {
			if (ch == p[x]) {
				break;
			}
		}
		if (x == m) break;
	}
	return ch;
}

/*判断非终结符是否已存在*/
bool checkWord(char ch, string Vn) {
	int i;
	bool flag = true;
	for (i = 0; i < Vn.size(); i++) {
		if (ch == Vn[i])
			flag = false;
	}
	return flag;
}

/*化简无用产生式*/
void simplify(struct grammar *gp) {
	string str;					//存储从开始符号可以到达的非终结符的序列
	int sVn[20];					//标记在哪个产生式
	sVn[0] = 0;
	str.insert(0, 1, gp->Vn[0]);			//初始化设置开始符号
	bool flag[20];
	flag[0] = false;				//标记哪个产生式需要删除
	char ch;
	int i, j, k, l, o;
	for (i = 0; i < str.size(); i++) {
		for (j = 3; j < gp->P[sVn[i]].size(); j++) {
			for (k = 0; k < m; k++) {
				if (gp->P[sVn[i]][j] < 'A' || gp->P[sVn[i]][j] > 'Z')    break;		//不是非终结符无需判断
				if (gp->P[sVn[i]][j] == gp->Vn[k]) {				//判断从开始符号可以到达的非终结符在Vn的哪个位置
					flag[k] = false;
					if (checkWord(gp->Vn[k], str)) {			//将在str中没有的有用非终结符插入str
						int e = str.size();
						sVn[e] = k;
						str.insert(str.size(), 1, gp->Vn[k]);
					}
					break;
				}
			}
		}
	}
	for (l = 0; l < m; l++) {			//删除无用的产生式和相应的非终结符
		char ch;
		if (flag[l]) {
			gp->Vn[l] = ' ';
			for (o = l + 1; o < m; o++) {
				ch = gp->Vn[o - 1];
				gp->Vn[o - 1] = gp->Vn[o];
				gp->Vn[o] = ch;
				gp->P[o - 1].clear();
				gp->P[o - 1].swap(gp->P[o]);
			}
			m--;
		}
	}
}

void remove_left_recursion(struct grammar *gp) {			//子函数，消除文法左递归
	int i, j, num_i, num_j, ipos, jpos;
	char ch_i, ch_j;
	for (i = 1; i < m + 1; i++) {
		bool repeat = true;					//标记相对于本轮循环上轮过程产生式是否有过变化，有则需要重新分割得到候选
		num_i = 0, ipos = 3;
		string str_i[20], restr_i[20], ex = "a";
		ch_i = gp->Vn[i - 1];							//获取当前要被处理的非终结符，即Pi		
		//分割产生式，得到右部的所有候选
		while (ipos != gp->P[i - 1].size() + 1) {
			str_i[num_i] = strsplit(gp->P[i - 1], ipos);
			restr_i[num_i] = str_i[num_i];
			ipos = ipos + str_i[num_i].size() + 1;
			num_i++;
		}
		for (j = 1; j <= i - 1; j++) {
			if (!repeat) {
				num_i = 0, ipos = 3;
				ch_i = gp->Vn[i - 1];							//重新获取当前要被处理的非终结符，即Pi		
				//分割产生式，得到右部的所有候选
				while (ipos != gp->P[i - 1].size() + 1) {
					str_i[num_i] = strsplit(gp->P[i - 1], ipos);
					restr_i[num_i] = str_i[num_i];
					ipos = ipos + str_i[num_i].size() + 1;
					num_i++;
				}
			}
			repeat = true;
			string str_j[20];
			int l;
			jpos = 3;
			num_j = 0;
			ch_j = gp->Vn[j - 1];							//获取当前要替换的非终结符，即Pj
			//分割产生式，得到右部的所有候选		
			while (jpos != gp->P[j - 1].size() + 1) {
				str_j[num_j] = strsplit(gp->P[j - 1], jpos);
				jpos = jpos + str_j[num_j].size() + 1;
				num_j++;
			}
			for (l = 0; l < num_i; l++) {		 	//逐个判断Pi的候选中是否含有Pj,有则进行替换	
				string change;
				ex[0] = ch_j;
				size_t pos = restr_i[l].find(ex);
				if (pos == string::npos) { continue; }			//无需替换
				else if (pos == 0) {							//Pj在该候选的第一个字符
					repeat = false;//
					string s = str_i[l].substr(1, str_i[l].size() - 1);		//得到候选中除Pj外的剩余部分
					str_i[l].swap(change);					//清空字符串
					int link = 0;
					while (1) {						//将Pj的所有候选与Pi中匹配的候选的剩余部分连接，中间还添加“|”
						if (link == num_j)	break;
						str_j[link] += s;
						if (link == num_j - 1)		str_i[l] += str_j[link];
						else		str_i[l] = str_i[l] + str_j[link] + "|";
						link++;
					}
				}
				else if (pos == str_i[l].size() - 1) {  //Pj在该候选的最后一个字符
					repeat = false;//
					string s = str_i[l].substr(0, str_i[l].size() - 1);
					str_i[l].swap(change);
					int link = 0;
					while (1) {
						if (link == num_j)	break;
						str_j[link] = s + str_j[link];
						if (link == num_j - 1)		str_i[l] += str_j[link];
						else		str_i[l] = str_i[l] + str_j[link] + "|";
						link++;
					}
				}
				else {					//Pj在该候选的中间
					repeat = false;//
					string s1 = str_i[l].substr(0, pos - 1);		//得到该候选中Pj前的字符串
					string s2 = str_i[l].substr(pos + 1, str_i[l].size() - pos - 1);//得到该候选中Pj后的字符串
					str_i[l].swap(change);
					int link = 0;
					while (1) {
						if (link == num_j)	break;
						str_j[link] = s1 + str_j[link] + s2;
						if (link == num_j - 1)		str_i[l] += str_j[link];
						else		str_i[l] = str_i[l] + str_j[link] + "|";
						link++;
					}
				}
			}
			string stri = "->";
			stri.insert(0, 1, ch_i);
			int index = 0;
			while (1) {		//将替换后的Pi的所有候选进行重组并存进文法中		
				if (index == num_i)		break;
				if (index == num_i - 1)		stri = stri + str_i[index];
				else	stri = stri + str_i[index] + "|";
				index++;
			}
			gp->P[i - 1] = stri;
		}
		//消除直接左递归
		string splitstr[30], resplitstr[30];
		int s = 0, ps = 3, h = 0;
		while (1) {					//分割替换后的产生式
			splitstr[s] = strsplit(gp->P[i - 1], ps);
			resplitstr[s] = splitstr[s];
			ps = ps + splitstr[s].size() + 1;
			if (ps == gp->P[i - 1].size() + 1)		break;
			s++;
		}
		string Pi = "->", Pichange = "->";
		Pi = ch_i + Pi;
		int link = 0, flag = -1;
		bool flagpos[30];
		char newWord;
		for (; link <= s; link++) {     //遍历所有候选，校验其中是否有左递归
			size_t posi;
			posi = resplitstr[link].find(ch_i);
			if (posi == 0) {				//存在直接左递归
				flag++;				//对候选标记左递归
				if (flag == 0) {			//处理出现左递归的第一个候选
					newWord = GetWord(gp->Vn);		//获取一个新的非终结符
					gp->Vn[m] = newWord;
					Pichange = newWord + Pichange;
					m++;
					splitstr[link] = splitstr[link].substr(1) + newWord;
					flagpos[link] = false;
					gp->P[m - 1] = Pichange + splitstr[link] + "|";
				}
				if (flag > 0) {
					splitstr[link] = splitstr[link].substr(1) + newWord;
					flagpos[link] = false;
					gp->P[m - 1] = gp->P[m - 1] + splitstr[link] + "|";
				}
			}
		}
		//对消除了直接左递归的候选进行重组成为产生式并存入文法
		if (flag > -1) {
			gp->P[i - 1] = "->";
			gp->P[i - 1].insert(0, 1, ch_i);
			for (; h <= s; h++) {
				if (flagpos[h]) {
					splitstr[h] += newWord;
					gp->P[i - 1] = gp->P[i - 1] + splitstr[h] + "|";
				}
			}
			gp->P[m - 1] += "@";
			gp->P[i - 1].erase(gp->P[i - 1].size() - 1, 1);
		}
	}
	simplify(gp);					//化简无用的产生式
}
//提取左因子（包括辅助函数）：
//对字符串数组排序
void str_sort(string *str, int num) {
	int i, j;
	for (i = 0; i < num; i++) {
		for (j = i + 1; j < num; j++) {
			if (str[i] > str[j])
				str[i].swap(str[j]);
		}
	}
}

/*子函数，提取左因子*/
void remove_left_gene(struct grammar *gp) {
	int rule_a, i, j, k, l, matchnum, oldmatchnum, resize, size;
	char ch, newWord;
	for (rule_a = 0; rule_a < m; rule_a++) {			//遍历所有产生式
		int bre = -1;						//标记已对产生式进行过左因子的提取
		int oldpo = 0;
		int num = 0, ps = 3;
		string str[30], restr[30];				//前者用于判断，需要保持原样，后者用于对有公共左因子的候选进行提取，可变
		while (ps != gp->P[rule_a].size() + 1) {			//分割替换后的产生式
			str[num] = strsplit(gp->P[rule_a], ps);
			restr[num] = str[num];
			ps = ps + str[num].size() + 1;
			num++;
		}
		str_sort(str, num);						//对所有候选按ASCII码进行排序，以便于简化对公共左因子的判断，只需先对前面候选判断
		str_sort(restr, num);
		int ca_i;
		string Pa = "->";
		Pa.insert(0, 1, gp->Vn[rule_a]);
		for (ca_i = 0; ca_i < num; ca_i++) {	//对排序后的候选进行重组并存入文法
			if (ca_i == num - 1)
				Pa += str[ca_i];
			else
				Pa += str[ca_i] + "|";
		}
		gp->P[rule_a] = Pa;
		int ipo = 0;		//辅助免除对已判断过有左因子的候选的遍历
		for (i = 0; i < num; i++, i += ipo) {	//遍历候选
			ipo = 0;
			size = 0;
			resize = 0;
			oldmatchnum = 0;
			int i_s = str[i].size();
			for (j = 0; j < i_s; j++) {			//对候选的逐个字符遍历
				matchnum = 0;				//标记除了本身，有几个候选有公共左因子
				ch = str[i][j];
				int kf = num;
				for (k = i + 1; k < num && k < kf; k++) { //对i之后的候选进行判断，是否有与i对应的公共左因子
					if (str[k][j] == ch) {			//有公共左因子
						matchnum++;
					}
					else {
						break;
					}
				}
				if (j == 0) {					//判断是否有公共左因子是i的第一个字符的情况，有则特别处理
					if (matchnum == 0)		break;
					else { oldmatchnum = matchnum; kf = i + 1 + oldmatchnum; }
				}
				else {
					if (oldmatchnum != matchnum)	break;
				}
			}
			/*有公共左因子的处理过程*/
			if (matchnum != oldmatchnum || j == i_s) {
				bre++;
				string match, repstr, can, newP;
				match = str[i].substr(0, j);			//获取公共左因子
				newWord = GetWord(gp->Vn);			//得到新的非终结符
				gp->Vn[m] = newWord;			//将新非终结符存入文法
				m++;
				newP = "->";
				newP.insert(0, 1, newWord);
				repstr = match + newWord;		//得到要被替换的有公共左因子的所有候选
				int renum = num;
				if (bre > 0) {				//若对同一产生式还存在另一个公共左因子（之前提取过一次左因子），需进行特别处理
					size = resize = 0;
					renum = 0;
					ps = 3;
					while (ps != gp->P[rule_a].size() + 1) {					//分割变化后的产生式
						restr[renum] = strsplit(gp->P[rule_a], ps);
						ps = ps + restr[renum].size() + 1;
						renum++;
					}
				}
				/*将已经提取过左因子的以候选为单位的字符串重新组合成产生式（包括新产生式）*/
				for (l = 0; l <= i - oldpo + oldmatchnum; l++) {
					if (l >= i - oldpo) {
						size += restr[l].size();
						can = restr[l].substr(j);
						if (can == "")		can = "@";
						if (l == i - oldpo + oldmatchnum)    newP += can;
						else	newP = newP + can + "|";
						gp->P[m - 1] = newP;
					}
					else {
						resize += restr[l].size();
						resize++;
					}
				}
				gp->P[rule_a].replace(resize + 3, size + oldmatchnum, repstr); //原产生式以替换的方式进行改变
				if (i + 1 + oldmatchnum > num) { break; }
				else	oldpo = ipo = oldmatchnum;
			}
		}
	}
}
