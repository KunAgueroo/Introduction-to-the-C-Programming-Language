#include "main.h"
#include <stdlib.h>
#include <unistd.h>
//Harshaavrdhan Reddipalli
//CS 198c
//Project wc-lite

// This is a "from-scratch challenge".
// Instructions on what the program should do are on the site.
// (Specifics are a way too involved for a pre-function comment, sorry. -蛇)
int main(int argc, char **argv) {
  // We offer a series of TODOs here, to help you organize your code and
  // implement in a step-wise fashion

  // TODO 1) Put declarations here of variables you will set during command line
  // parsing.
  //   Some of these you may discover/invent as you go, but it is clear you will
  //   need:
  //   - Some way of storing which of the -c, -w, -n, and -l flags are active
  //   - The width to use when printing file names (affected by the -f flag)
  //   - The output file
  // You should give a default value for each variable.  Note that for an output
  // FILE *, a default value of stdout is perfectly fine.  Concerning the flags,
  // the default should be something that means "false".  You will need, in the
  // next step, to keep track of whether any of the flags are set explicitly on
  // the command line, so you'll need an extra variable for that, e.g., any_set.
  int len = 20;
  int ofS = 0;
  int lineS = 0 ,lineC = 0,lineTotal = 0;
  int numS =0, numC = 0,numTotal = 0;
  int wordS = 0,wordC = 0, wordTotal = 0;
  int charS=0,charC = 0, charTotal = 0;
  FILE *out;
  FILE *file;
  char* name;
  int opt;
  int defaultS = 1;
  // TODO 2) Write a suitable loop here that repeatedly calls getopt until the
  //   results is -1.  The body of the loop should switch on the flag found, and
  //   have a case for each of the command line flags.  Each case may save a
  //   value, do some action, or a combination of both.  Adjust any_set as
  //   needed. After the loop, use any_set to determine whether to set the
  //   default overall flag configuration.  (This can't be done before the
  //   getopt loop because you don't know yet whether any flags were given on
  //   the cmmand line.)
 
    while((opt=getopt(argc,argv,"cwnlo:f:"))>=0){
    defaultS = 0;
    switch(opt){
      case 'c':
        charS=1;
        break;
      case 'w':
        wordS = 1;
        break;
      case 'n':
        numS=1;
        break;
      case 'l':
        lineS = 1;
        break;
      case 'o':
        ofS=1;
        name = optarg;
        out = fopen(name,"w");
      if(out==NULL)
      {
        fprintf(stderr,"Error in Output");
        exit(0);
      }
      break;
      case 'f':
        len=atoi(optarg);
        break;
      default:
        charS=1;
        wordS=1;
        lineS=1;
        break;
    }
  }
  if(defaultS){
    charS=1;
    wordS=1;
    lineS=1;
  }
  
  for(int i = optind;i<argc;i++){
    file = fopen(argv[i],"r");
    if(file==NULL){
      fprintf(stderr, "%s: No such file or directory\n",argv[i]);
      continue;
    }

  // TODO 3) Put declarations here of the counts you will accumulate, of
  // characters, lines, words, and numbers.  You will need one set of counts
  // to accumulate within a file, and a separate set of running totals.
  // This is also a place where you can declare buffer pointer and size
  // variables for use by getline (see below).

    size_t buffS;
    char *ptr = NULL;
    int num_chars = 0;
    charC = 0;
    lineC = 0;
    wordC = 0;
    numC = 0;
    int offset = 0;
    
  // TODO 4) Write a suitable loop that will process each file.  Note that
  //   optind will give the index in argc of the first file name.
  //   For each file name:
  //     - Try to open the file for reading.  If that fails, print the required
  //       message and go on to the next iteration of the loop.
  //     - Set the within-file counters to zero.
  //     - Loop, reading each line of the file with getline.
  //       - You can immediately adjust your within-file character and line
  //         counts; the number of characters read is the result that getline
  //         returns :-) .
  //       - Use a suitable loop to count words (groups of non-delimiters
  //         actually), by alternating calls to strcpsn and strspn.  (Read
  //         the slides for this module, and see the example below!)
  //       - Use a suitable loop to count numbers by similarly alternating calls
  //         to strspn and strcspn.  The two loops will have some differences.
  //     - Output a line with this file's information.  We found it handy to
  //       write an output_line function, passing the file name, counts, and
  //       flag values.
  //     - Add the per-file counts into the running totals.
  //     - Close the input file
  //
  // Example loop using strspn and strcspn.  This code will count the number
  // of runs of the letter 'x' in a string.  (A "run" is a sequence of one or
  // more of the same letter.)
  //   char *s = ... the string to be searched ...
  //   int xruns = 0;
  //   char *p = s;
  //   for (char *p = s; *p != 0; /* nothing */) {  // stops at end of string
  //      p += strcpsn(p, "x");  // bumps p to skip non-x characters
  //      int nx = strspn(p, "x");
  //      p += nx;
  //      xruns += (nx != 0);  // adds a 0/1 value to xruns
  //   }
  // Make sure you understand this loop before coding your own!
  // Certainly there are amny variations that will act the same;
  // The above is one of the most concise, and exploits a number
  // of C coding techniques.
  //
  // The count-numbers loop will be very similar to the above.
  // The count-words loop will be more different because you'll use
  // the set of delimiters as the second argument to strspn/strcspn,
  // but you want to count the runs of NON-delimiters, not of delimiters.
 while((num_chars=getline(&ptr,&buffS,file))!=-1)
 {
      charC = charC+num_chars;
      lineC++;
      offset=0;
    while(strcspn(ptr+offset," \n")!=0)
    {
	    offset = offset +strcspn(ptr+offset, " \n")+1;
	    wordC++;
	      if(offset>num_chars)
      {
        break;
      }
    }
      offset=0;
    while(1)
    {
	    offset=offset+strcspn(ptr+offset,"0123456789");
	      if(strspn(ptr+offset,"0123456789")==0)
      {   
        break;
      }
	    offset=offset+strspn(ptr+offset,"0123456789");
	    numC++;
    }
  }
    free(ptr);
    
    if(ofS){
      fprintf(out,"%-*s:",len,argv[i]);
      if(charS)
      {
        fprintf(out," %5i",charC);
      }
      if(wordS)
      {
        fprintf(out," %5i",wordC);
      }
      if(numS)
      {
        fprintf(out," %5i",numC);
      }
      if(lineS)
      {
        fprintf(out," %5i",lineC);
      }
      fprintf(out,"\n");
    }else{
      fprintf(stdout,"%-*s:",len,argv[i]);
      if(charS)
      {
        fprintf(stdout," %5i",charC);
      }
      if(wordS)
      {
        fprintf(stdout," %5i",wordC);
      }
      if(numS)
      {
        fprintf(stdout," %5i",numC);
      }
      if(lineS)
      {
        fprintf(stdout," %5i",lineC);
      }
      fprintf(stdout,"\n");
    }
    fclose(file);
    charTotal=charTotal+charC;
    wordTotal=wordTotal+wordC;
    numTotal=numTotal+numC;
    lineTotal=lineTotal+lineC;
  }
  if(ofS){
    fprintf(out,"%-*s:",len,"total");
    if(charS){
      fprintf(out," %5i",charTotal);
      }
    if(wordS)
    {
      fprintf(out," %5i",wordTotal);
    }
    if(numS)
    {
      fprintf(out, "%5i",numTotal);
    }
    if(lineS)
    {
      fprintf(out," %5i",lineTotal);
    }
    fprintf(out,"\n");
    fclose(out);
  }else{
    fprintf(stdout,"%-*s:",len,"total");
    if(charS)
    {
      fprintf(stdout," %5i",charTotal);
    }
    if(wordS)
    {
      fprintf(stdout," %5i",wordTotal);
      }
    if(numS)
    {
      fprintf(stdout," %5i",numTotal);
    }
    if(lineS)
    {
      fprintf(stdout," %5i",lineTotal);
    }
    fprintf(stdout,"\n");
    }
  return 0;
  // TODO 5) Finish up: output the totals (using output_line), free getline's
  //   line buffer, and close the output file.
}
