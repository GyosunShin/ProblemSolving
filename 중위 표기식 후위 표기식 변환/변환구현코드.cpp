#include <cstring> 
#include <cstdlib>

int getOpPrec(char op){
	// 반환되는 값이 클수록 우선순위 높다 
	switch(op){
		case '*':
		case '/':
			return 5;
		case '+':
		case '-':
			return 3;
		case '(':
			return 1;
	}
	
	return -1;
}

int whoPrecOp(char op1, char op2) {
	int op1Prec = getOpPrec(op1);	int op2Prec = getOpPrec(op2);
	
	if(op1Prec > op2Prec)	return 1;
	else if(op1Prec < op2Prec)	return -1;
	else	return 0;
}

void ConvToRPNExp(char exp[]){
	
	Stack stack;
	int expLen = strlen(exp);
	char* convExp = (char*)malloc(expLen + 1);
	
	int idx = 0;
	char tok, popOp;
	
	memset(convExp, 0, sizeof(char) * expLen + 1);
	StackInit(&stack);
	
	for(int i = 0 ; i < expLen ; ++i){
		tok = exp[i];
		if(isdigit(tok))	convExp[idx++] = tok;
		else{
			switch(tok){
				case '(':
					SPush(&stack, tok);
					break;
					
				case ')':
					while(true){
						popOp = SPop(&stack);
						if(popOp == '(')	break;
						convExp[idx++] = popOp;
					}
					break;
					
				case '+': case '-': case '*': case '/':
					while(!SIsEmpty(&stack) &&
					whoPrecOp(SPeek(&stack), tok) >= 0){
						convExp[idx++] = SPop(&stack);
					}
					
					SPush(&stack, tok);
					break;
			}
			
		}
		
	}
	
	while(!IsEmpty(&stack)){
		convExp[idx++] = SPop(&stack);
	}
	
	strcpy(exp, convExp);
	free(convExp);
}








