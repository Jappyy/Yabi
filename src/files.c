#include "../include/files.h"
#include "../include/args.h"

char instructions[] = "+-<>.,[]!";


bool check_file_extension(const char* filename, const char* extension)
{
   char* ptr;
   char* temp;

   if((temp = strstr(filename, extension)) != NULL) //if the extension is present inside of the filename string
   {  
      do 
      {
         ptr = temp;
         ++temp; 
         temp = strstr(temp, extension);

      } while(temp != NULL); // this loop makes sure that ptr points to the last instance of the extension inside of the filename string
     
      if(strcmp(ptr, extension) != 0) // if ptr doesn't correspond with the extension, return false
         return false;
   }

   else return false; // if the extension is not present inside of the filename string, return false

   return true;
}

FILE* open_file(const char* filename, const char* folder, const char* extension, const char* mode)
{
   char *ptr = NULL;

   char* path = NULL;
   if ((path = malloc(strlen(filename) + strlen(folder) + strlen(extension) + sizeof(__FILE__))) == NULL) //that's definitely more space than actually needed, but better safe than sorry
      print_message(FUNCTION_FAILURE_ERROR, "malloc()");

   memcpy(path, __FILE__, sizeof(__FILE__));

   ptr = strstr(path, "src");
   memset(ptr, 0, strlen(ptr));

   strcat(path, folder);
   strcat(path, filename);
   
   if (!check_file_extension(path, extension))
      strcat(path, extension);
   
   FILE* fp = NULL;
   fp = fopen(path, mode);

   free(path);

   return fp; 
}


FILE* open_input(command_line_args* args)
{
   FILE *source = NULL;

   source = open_file(args->input_filename, "examples/", ".b", "r");

   if(!source)
      source = open_file(args->input_filename, "examples/", ".bf", "r");

   if(!source)
      print_message(FILE_NOT_FOUND_ERROR, args->input_filename);

   return source;
}


FILE* open_output(command_line_args* args)
{
   FILE* output = NULL;

   if(args->flags.compiler)
      output = open_file(args->output_filename, "output/", ".c", "w");

   else // if (args->flags.debug)
      output = open_file(args->output_filename, "log/", ".log", "w");

   if (!output)
      print_message(FUNCTION_FAILURE_ERROR, "fopen()");

   return output;
}

void info(FILE* source)
{
   
   char buf[300] = {0};

   if (fgets(buf, sizeof(buf), source) == NULL)
      print_message(FUNCTION_FAILURE_ERROR, "fgets()");
   
   if (strpbrk(buf, instructions) != NULL || *buf == '\n')
      print(stdout, "No description found.\n");
   
   else
      print(stdout, "%s", buf);
   
   exit(EXIT_SUCCESS);
}

char* read_file(FILE* source)
{
   char* temp;

   fseek(source, 0, SEEK_END);
   size_t len = (size_t) ftell(source);

   if ((temp = malloc(len * sizeof(char) + 1)) == NULL)
      print_message(FUNCTION_FAILURE_ERROR, "malloc()");

   fseek(source, 0, SEEK_SET);


   if ((fread(temp,1, len, source)) == 0)
      print_message(FUNCTION_FAILURE_ERROR, "fread()");
   
   temp[len] = '\0';

   char* buf = malloc (len * sizeof(char) + 1);

   int j = 0;
   for (size_t i = 0; i < len; i++)
   {
      if (strchr(instructions, temp[i]) != NULL)
      {
         buf[j] = temp[i];
         j++;
      }
   }

   buf[j] = '\0';

   buf = realloc(buf, strlen(buf));

   free(temp);

   return buf;
}