/*�ַ����ָ����������ʽ�Ҳ��ĺ�ѡ����,ʶ��|������posλ��ʼ�ָ�*/
string strsplit(string strTok, int pos) {
	string str;
	size_t position;
	position = strTok.find("|", pos);
	if (position != string::npos) {			//�ҵ��ˡ�|��
		str = strTok.substr(pos, position - pos);
	}
	else {								//û�ҵ�
		str = strTok.substr(pos, strTok.size() - pos);
	}
	return str;
}
/*���һ���ķ�����δ����ķ��ս�������ض��Ĵ�д��ĸ*/
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

/*�жϷ��ս���Ƿ��Ѵ���*/
bool checkWord(char ch, string Vn) {
	int i;
	bool flag = true;
	for (i = 0; i < Vn.size(); i++) {
		if (ch == Vn[i])
			flag = false;
	}
	return flag;
}

/*�������ò���ʽ*/
void simplify(struct grammar *gp) {
	string str;					//�洢�ӿ�ʼ���ſ��Ե���ķ��ս��������
	int sVn[20];					//������ĸ�����ʽ
	sVn[0] = 0;
	str.insert(0, 1, gp->Vn[0]);			//��ʼ�����ÿ�ʼ����
	bool flag[20];
	flag[0] = false;				//����ĸ�����ʽ��Ҫɾ��
	char ch;
	int i, j, k, l, o;
	for (i = 0; i < str.size(); i++) {
		for (j = 3; j < gp->P[sVn[i]].size(); j++) {
			for (k = 0; k < m; k++) {
				if (gp->P[sVn[i]][j] < 'A' || gp->P[sVn[i]][j] > 'Z')    break;		//���Ƿ��ս�������ж�
				if (gp->P[sVn[i]][j] == gp->Vn[k]) {				//�жϴӿ�ʼ���ſ��Ե���ķ��ս����Vn���ĸ�λ��
					flag[k] = false;
					if (checkWord(gp->Vn[k], str)) {			//����str��û�е����÷��ս������str
						int e = str.size();
						sVn[e] = k;
						str.insert(str.size(), 1, gp->Vn[k]);
					}
					break;
				}
			}
		}
	}
	for (l = 0; l < m; l++) {			//ɾ�����õĲ���ʽ����Ӧ�ķ��ս��
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

void remove_left_recursion(struct grammar *gp) {			//�Ӻ����������ķ���ݹ�
	int i, j, num_i, num_j, ipos, jpos;
	char ch_i, ch_j;
	for (i = 1; i < m + 1; i++) {
		bool repeat = true;					//�������ڱ���ѭ�����ֹ��̲���ʽ�Ƿ��й��仯��������Ҫ���·ָ�õ���ѡ
		num_i = 0, ipos = 3;
		string str_i[20], restr_i[20], ex = "a";
		ch_i = gp->Vn[i - 1];							//��ȡ��ǰҪ������ķ��ս������Pi		
		//�ָ����ʽ���õ��Ҳ������к�ѡ
		while (ipos != gp->P[i - 1].size() + 1) {
			str_i[num_i] = strsplit(gp->P[i - 1], ipos);
			restr_i[num_i] = str_i[num_i];
			ipos = ipos + str_i[num_i].size() + 1;
			num_i++;
		}
		for (j = 1; j <= i - 1; j++) {
			if (!repeat) {
				num_i = 0, ipos = 3;
				ch_i = gp->Vn[i - 1];							//���»�ȡ��ǰҪ������ķ��ս������Pi		
				//�ָ����ʽ���õ��Ҳ������к�ѡ
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
			ch_j = gp->Vn[j - 1];							//��ȡ��ǰҪ�滻�ķ��ս������Pj
			//�ָ����ʽ���õ��Ҳ������к�ѡ		
			while (jpos != gp->P[j - 1].size() + 1) {
				str_j[num_j] = strsplit(gp->P[j - 1], jpos);
				jpos = jpos + str_j[num_j].size() + 1;
				num_j++;
			}
			for (l = 0; l < num_i; l++) {		 	//����ж�Pi�ĺ�ѡ���Ƿ���Pj,��������滻	
				string change;
				ex[0] = ch_j;
				size_t pos = restr_i[l].find(ex);
				if (pos == string::npos) { continue; }			//�����滻
				else if (pos == 0) {							//Pj�ڸú�ѡ�ĵ�һ���ַ�
					repeat = false;//
					string s = str_i[l].substr(1, str_i[l].size() - 1);		//�õ���ѡ�г�Pj���ʣ�ಿ��
					str_i[l].swap(change);					//����ַ���
					int link = 0;
					while (1) {						//��Pj�����к�ѡ��Pi��ƥ��ĺ�ѡ��ʣ�ಿ�����ӣ��м仹��ӡ�|��
						if (link == num_j)	break;
						str_j[link] += s;
						if (link == num_j - 1)		str_i[l] += str_j[link];
						else		str_i[l] = str_i[l] + str_j[link] + "|";
						link++;
					}
				}
				else if (pos == str_i[l].size() - 1) {  //Pj�ڸú�ѡ�����һ���ַ�
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
				else {					//Pj�ڸú�ѡ���м�
					repeat = false;//
					string s1 = str_i[l].substr(0, pos - 1);		//�õ��ú�ѡ��Pjǰ���ַ���
					string s2 = str_i[l].substr(pos + 1, str_i[l].size() - pos - 1);//�õ��ú�ѡ��Pj����ַ���
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
			while (1) {		//���滻���Pi�����к�ѡ�������鲢����ķ���		
				if (index == num_i)		break;
				if (index == num_i - 1)		stri = stri + str_i[index];
				else	stri = stri + str_i[index] + "|";
				index++;
			}
			gp->P[i - 1] = stri;
		}
		//����ֱ����ݹ�
		string splitstr[30], resplitstr[30];
		int s = 0, ps = 3, h = 0;
		while (1) {					//�ָ��滻��Ĳ���ʽ
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
		for (; link <= s; link++) {     //�������к�ѡ��У�������Ƿ�����ݹ�
			size_t posi;
			posi = resplitstr[link].find(ch_i);
			if (posi == 0) {				//����ֱ����ݹ�
				flag++;				//�Ժ�ѡ�����ݹ�
				if (flag == 0) {			//���������ݹ�ĵ�һ����ѡ
					newWord = GetWord(gp->Vn);		//��ȡһ���µķ��ս��
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
		//��������ֱ����ݹ�ĺ�ѡ���������Ϊ����ʽ�������ķ�
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
	simplify(gp);					//�������õĲ���ʽ
}
//��ȡ�����ӣ�����������������
//���ַ�����������
void str_sort(string *str, int num) {
	int i, j;
	for (i = 0; i < num; i++) {
		for (j = i + 1; j < num; j++) {
			if (str[i] > str[j])
				str[i].swap(str[j]);
		}
	}
}

/*�Ӻ�������ȡ������*/
void remove_left_gene(struct grammar *gp) {
	int rule_a, i, j, k, l, matchnum, oldmatchnum, resize, size;
	char ch, newWord;
	for (rule_a = 0; rule_a < m; rule_a++) {			//�������в���ʽ
		int bre = -1;						//����ѶԲ���ʽ���й������ӵ���ȡ
		int oldpo = 0;
		int num = 0, ps = 3;
		string str[30], restr[30];				//ǰ�������жϣ���Ҫ����ԭ�����������ڶ��й��������ӵĺ�ѡ������ȡ���ɱ�
		while (ps != gp->P[rule_a].size() + 1) {			//�ָ��滻��Ĳ���ʽ
			str[num] = strsplit(gp->P[rule_a], ps);
			restr[num] = str[num];
			ps = ps + str[num].size() + 1;
			num++;
		}
		str_sort(str, num);						//�����к�ѡ��ASCII����������Ա��ڼ򻯶Թ��������ӵ��жϣ�ֻ���ȶ�ǰ���ѡ�ж�
		str_sort(restr, num);
		int ca_i;
		string Pa = "->";
		Pa.insert(0, 1, gp->Vn[rule_a]);
		for (ca_i = 0; ca_i < num; ca_i++) {	//�������ĺ�ѡ�������鲢�����ķ�
			if (ca_i == num - 1)
				Pa += str[ca_i];
			else
				Pa += str[ca_i] + "|";
		}
		gp->P[rule_a] = Pa;
		int ipo = 0;		//������������жϹ��������ӵĺ�ѡ�ı���
		for (i = 0; i < num; i++, i += ipo) {	//������ѡ
			ipo = 0;
			size = 0;
			resize = 0;
			oldmatchnum = 0;
			int i_s = str[i].size();
			for (j = 0; j < i_s; j++) {			//�Ժ�ѡ������ַ�����
				matchnum = 0;				//��ǳ��˱����м�����ѡ�й���������
				ch = str[i][j];
				int kf = num;
				for (k = i + 1; k < num && k < kf; k++) { //��i֮��ĺ�ѡ�����жϣ��Ƿ�����i��Ӧ�Ĺ���������
					if (str[k][j] == ch) {			//�й���������
						matchnum++;
					}
					else {
						break;
					}
				}
				if (j == 0) {					//�ж��Ƿ��й�����������i�ĵ�һ���ַ�������������ر���
					if (matchnum == 0)		break;
					else { oldmatchnum = matchnum; kf = i + 1 + oldmatchnum; }
				}
				else {
					if (oldmatchnum != matchnum)	break;
				}
			}
			/*�й��������ӵĴ������*/
			if (matchnum != oldmatchnum || j == i_s) {
				bre++;
				string match, repstr, can, newP;
				match = str[i].substr(0, j);			//��ȡ����������
				newWord = GetWord(gp->Vn);			//�õ��µķ��ս��
				gp->Vn[m] = newWord;			//���·��ս�������ķ�
				m++;
				newP = "->";
				newP.insert(0, 1, newWord);
				repstr = match + newWord;		//�õ�Ҫ���滻���й��������ӵ����к�ѡ
				int renum = num;
				if (bre > 0) {				//����ͬһ����ʽ��������һ�����������ӣ�֮ǰ��ȡ��һ�������ӣ���������ر���
					size = resize = 0;
					renum = 0;
					ps = 3;
					while (ps != gp->P[rule_a].size() + 1) {					//�ָ�仯��Ĳ���ʽ
						restr[renum] = strsplit(gp->P[rule_a], ps);
						ps = ps + restr[renum].size() + 1;
						renum++;
					}
				}
				/*���Ѿ���ȡ�������ӵ��Ժ�ѡΪ��λ���ַ���������ϳɲ���ʽ�������²���ʽ��*/
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
				gp->P[rule_a].replace(resize + 3, size + oldmatchnum, repstr); //ԭ����ʽ���滻�ķ�ʽ���иı�
				if (i + 1 + oldmatchnum > num) { break; }
				else	oldpo = ipo = oldmatchnum;
			}
		}
	}
}
