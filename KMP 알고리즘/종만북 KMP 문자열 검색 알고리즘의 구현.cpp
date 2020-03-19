
// N���� �ڱ� �ڽ��� ã���鼭 ��Ÿ���� �κ� ��ġ�� �̿��� pi[] rPtks
// pi[i] = N[..i]�� ���̻絵 �ǰ� ���λ絵 �Ǵ� ���ڿ��� �ִ� ����
vector<int>  getPartialMatch(const string& N){
	
	int m = N.size();
	vector<int> pi(m, 0);
	
	// KMP�� �ڽ��� ã�´�.
	// N�� N���� ã�´�. begin = 0�̸� �ڱ� �ڽ��� ã�ƹ����ϱ� �ȵ�!
	int begin = 1;
	int matched = 0;
	
	// ���� ���ڰ� N�� ���� ������ ������ ã���鼭 �κ� ��ġ�� ��� ���
	while(begin + matched < m) {
		
		if(N[begin + matched] == N[matched]){
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else{
			if(matched == 0)	++begin;
			else{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return pi;
}


// '¤����'  H�� ��� �κ� ���ڿ��� '�ٴ�' N�� �����ϴ� ���� ��ġ���� ��� ��ȯ
vector<int> kmpSearch(const string& H, const string& N){
	
	int n = H.size();
	int m = N.size();
	
	vector<int> ret;
	
	// pi[i] = N[..i]�� ���̻絵 �ǰ� ���λ絵 �Ǵ� ���ڿ��� �ִ� ���� 
	vector<int> pi = getPartialMatch(N);
	
	// begin = matched = 0�������� ����
	int begin = 0;
	int matched = 0;
	
	while(begin <= n - m) {
		// ���� ¤������ �ش� ���ڰ� �ٴ��� �ش� ���ڿ� ���ٸ�
		if(matched < m && H[begin + matched] == N[matched]) {
			++matched;
			if(matched == m)	ret.push_back(begin);
		}
		else{
			// ���� : matched�� 0�� ��쿡�� ���� ĭ�������� ���
			if(matched == 0) 	++begin;
			else{
				begin += matched - pi[matched-1];
				
				// begin�� �Ű�ٰ� �ص� ó������ �ٽ� ������ �ʿ� ����.
				// �ű� �Ŀ��� pi[matched-1]��ŭ�� �׻� ��ġ�ϱ� ����
				matched = pi[matched-1] ;
			}
		}
	}
	
	return ret;
}
