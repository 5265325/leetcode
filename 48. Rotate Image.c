void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
//     int i, j;
//     int temp;
    
//     for(j = 0; j < matrixRowSize/2; j++) {
//         for(i = j; i < matrixRowSize - 1 - j; i++) {
//             temp = matrix[j][i];
//             matrix[j][i] = matrix[matrixRowSize - i - 1][j];
//             matrix[matrixRowSize - i - 1][j] = matrix[matrixRowSize - j - 1][matrixRowSize - i - 1];
//             matrix[matrixRowSize - j - 1][matrixRowSize - i - 1] = matrix[i][matrixRowSize - j - 1];
//             matrix[i][matrixRowSize - j - 1] = temp;
            
//         }
        
//     }
    
    if(matrixRowSize>=2)
    {
        int i,j,k,time=1,temp;
        for(i=1;i<=time;i++)
        {
            for(j=0;j<time;j++)
            {
                temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
            time++;
            if(time==matrixRowSize)
                break;
        }

        time=matrixRowSize/2; 
        for(i=0;i<matrixRowSize;i++)
        {
            for(j=0,k=matrixRowSize-1;j<time;j++,k--)
            {
                temp=matrix[i][j];
                matrix[i][j]=matrix[i][k];
                matrix[i][k]=temp;
            }
        }
    }
}