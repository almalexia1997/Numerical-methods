Matrix Povorot(Matrix A) {
		int i=0, j=0;
		double max = 0;
		Matrix T(size); //матрица поворота
		T.Kroneker(); //придаем всем элементам значения как в единичной
		for (int k = 0; k<size; ++k)
			for (int l = 0; l<size; ++l)
				if (k != l && abs(A[k][l])>=max){ //ищем индексы i и j
					max = A[k][l];
					i = k; j = l;
				}
		cout << "\ni=" << i << "\nj=" << j << endl;
		double p = 2.0 * A[i][j] / (A[i][i] - A[j][j]);
		double sgnp;
		(p>0) ? sgnp = 1 : sgnp = -1;
		double fi = 0.5*atan(p); //находим угол фи
		//double c = sqrt(0.5 * (1.0 + (1.0/sqrt(1.0+p*p)))); //косинус фи
		//double s = sgnp*sqrt(0.5 * (1.0 - (1.0 / sqrt(1.0 + p*p))));	//синус фи
		double c = cos(fi);
		double s = sin(fi);
		//определяем матрицу поворота
		T.A[i][i] = c;
		T.A[i][j] = -s;
		T.A[j][i] = s;
		T.A[j][j] = c;
		cout << "\nT:" << endl; T.showData();
		return T; //возвращаем матрицу поворота
	}

	Matrix Jacoby(Matrix A){
		Matrix B(size); //матрица промежуточного умножения
		Matrix V(size);
		V = A;
		Matrix T(size); //матрица поворота
		Matrix Tt(size);//транспонированная к ней матрица
		double max = 0;
		for (int i = 0; i<size; i++)
			for (int j = 0; j < size; j++)
				if (i != j && i<j && abs(V[i][j]) >= max)
					max = abs(V[i][j]);
		int ch=0;
		while (abs(max)>eps){
			T = V.Povorot(V);//определяем матрицу поворота
			Tt = T.Trans(size);//определяем транспонированную к ней матрицу
			B = Tt.MultMatrix(V);//находим T*A
			V = B.MultMatrix(T); //находим T*AT и находим
			double max = 0;
			for (int i = 0; i<size; i++)
				for (int j = 0; j < size; j++)
					if (i != j && i<j && abs(V[i][j]) >= max)
						max = abs(V[i][j]);
			ch++;
			if(ch==2)
				break;
		}
		return V;
	}
