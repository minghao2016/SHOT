//=============================================================================
/*! _zgbmatrix+_zgematrix operator */
inline _zgematrix operator+(const _zgbmatrix& matA, const _zgematrix& matB)
{VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if(matA.n!=matB.n || matA.m!=matB.m){
    ERROR_REPORT;
    std::cerr << "These two matrises can not make a summation." << std::endl
              << "Your input was (" << matA.m << "x" << matA.n << ") + (" << matB.m << "x" << matB.n << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  for(long i=0; i<matA.m; i++){
    for(long j=std::max(long(0),i-matA.kl); j<std::min(matA.n,i+matA.ku+1); j++){
      matB(i,j)+=matA(i,j);
    }
  }
  
  matA.destroy();
  return matB;
}

//=============================================================================
/*! _zgbmatrix-_zgematrix operator */
inline _zgematrix operator-(const _zgbmatrix& matA, const _zgematrix& matB)
{VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if(matA.n!=matB.n || matA.m!=matB.m){
    ERROR_REPORT;
    std::cerr << "These two matrises can not make a summation." << std::endl
              << "Your input was (" << matA.m << "x" << matA.n << ") + (" << matB.m << "x" << matB.n << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  for(long i=0; i<matA.m; i++){
    for(long j=std::max(long(0),i-matA.kl); j<std::min(matA.n,i+matA.ku+1); j++){
      matB(i,j) =matA(i,j)-matB(i,j);
    }
  }
  
  matA.destroy();
  return matB;
}

//=============================================================================
/*! _zgbmatrix*_zgematrix operator */
inline _zgematrix operator*(const _zgbmatrix& matA, const _zgematrix& matB)
{VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if(matA.n!=matB.m){
    ERROR_REPORT;
    std::cerr << "These two matrises can not make a product." << std::endl
              << "Your input was (" << matA.m << "x" << matA.n << ") * (" << matB.m << "x" << matB.n << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  zgematrix newmat( matA.m, matB.n );
  newmat.zero();
  
  for(long i=0; i<newmat.m; i++){
    for(long j=0; j<newmat.n; j++){
      for(long k=std::max(long(0),i-matA.kl); k<std::min(matA.n,i+matA.ku+1); k++){
        newmat(i,j)+=matA(i,k)*matB(k,j);
      }
    }
  }
  
  matA.destroy();
  matB.destroy();
  return _(newmat);
}
