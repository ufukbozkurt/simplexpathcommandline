
#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>

xmlDocPtr parseFile(const char *filename){
    xmlDocPtr doc; 
    xmlKeepBlanksDefault(0);
    doc = xmlParseFile(filename);
    if (doc == NULL) {
        printf("Failed to parse %s\n", filename);
        return NULL;
    }
    return doc;
}

xmlXPathObjectPtr getNodeSet(xmlDocPtr doc, xmlChar *xPath){
    xmlXPathContextPtr context;
    xmlXPathObjectPtr result;

    context = xmlXPathNewContext(doc);
    if(context == NULL) return NULL;

    result = xmlXPathEvalExpression(xPath, context);
    if(result == NULL) return NULL;

    xmlXPathFreeContext(context);

    return result;
}

int main(int argc, char **argv) {

    if(argc != 2){
        printf("Usage: %s <documentPath>\n",argv[0]);
        return -1;
    }
    printf("%s\n",argv[1]);
    xmlDocPtr doc = parseFile(argv[1]);
    xmlXPathObjectPtr result;
    xmlNodeSetPtr nodeset;
    xmlChar *key;
    char expression[64];
    int i;

    while( 1 ){
        printf("\nEXPRESSION: ");
        scanf("%s",expression);
        if(strcmp(expression,":QUIT") == 0) break;

        result = getNodeSet (doc, (xmlChar*) expression);
        if(result==NULL){
            printf("ERROR!");
        }
        else{
            printf("RESULT:\n");
            if(!xmlXPathNodeSetIsEmpty(result->nodesetval)){
                nodeset = result->nodesetval;
                for( i = 0 ; i < nodeset->nodeNr ; i++){
                    xmlBufferPtr buffer = xmlBufferCreate();
                    xmlNodeDump(buffer, doc, nodeset->nodeTab[i], 0, 1);
                    printf("%s\n", buffer->content);
                    xmlFree(buffer);
                }
            }
        }

    }

    xmlFreeDoc(doc);
    xmlCleanupParser();

    return 0;
}