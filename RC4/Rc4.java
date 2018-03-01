//
//  State.java
//  RC4AsciiArt
//
//  Created by burton rosenberg on Fri Aug 23 2002.
//  Copyright (c) 2002 __MyCompanyName__. All rights reserved.
//

public class Rc4 {

    private static final int DEFAULT_BITS = 8 ;
    
    int [] s ;
    int sz ;
    int i_s, j_s, t_s ; 
    
    int [] k ;
    int kz ;
    
    Rc4(int [] key) {
       this(key, DEFAULT_BITS) ;
    }
    
    Rc4(int [] key, int bits) {
        sz = 0x01 << bits ;
        s = new int[sz] ;
        init(key) ;
    }
    
    int init() {
       return init(k) ;
    }
    
    int init(int [] key) {
       kz = key.length ;
       k = new int[kz] ;
       for ( int i=0; i<kz; i++ ) k[i] = key[i]%sz ;
       for ( int i=0; i<s.length; i++ ) s[i] = i ;
       int j = 0 ;
       for ( int i=0; i<s.length; i++ ) {
           int si = s[i] ;
           j = (j + si + k[i%kz])%sz ;
           s[i] = s[j] ;
           s[j] = si ;
       
       }
       i_s = j_s = 0 ;
       return 0 ;
    }
    
    void printState() { // printState(null) ; }
       printState_x() ;
    }

    void printState_x() {
       System.out.print("i: "+i_s+", j: "+j_s+" s: " ) ;
       for ( int i=0; i<sz; i++ ) System.out.print(" "+s[i]+" ") ;
       System.out.println() ;
    }
 
    void printState(String msg) {
       if (msg!=null) System.out.println(msg) ;
       for ( int i=0; i<sz; i++ ) {
          if ( i==t_s ) System.out.print("[") ;
          if ( i==i_s ) System.out.print("_") ;
          if ( i==j_s ) System.out.print("_") ;
          System.out.print(s[i]) ;
          if ( i==i_s ) System.out.print("_") ;
          if ( i==j_s ) System.out.print("_") ;
          if ( i==t_s ) System.out.print("]") ;
          System.out.print(" : " ) ;
       }
       System.out.println() ;
    }
    
    int update() {
        int si, sj ;
        i_s = ( i_s+1 ) % sz ;
        j_s = (j_s + (si=s[i_s])) % sz ;
        s[i_s] = (sj=s[j_s]) ;
        s[j_s] = si ;
        return s[t_s=((si+sj)%sz)] ;
    }
    
}
