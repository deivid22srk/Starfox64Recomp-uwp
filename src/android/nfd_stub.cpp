#include "nfd.h"
#include <cstdlib>

nfdresult_t NFD_Init(void) {
    return NFD_OKAY;
}

void NFD_Quit(void) {
}

void NFD_FreePathN(nfdnchar_t* outPath) {
    if (outPath) free(outPath);
}

nfdresult_t NFD_OpenDialogN(nfdnchar_t** outPath, const nfdnfilteritem_t* filterList, nfdfiltersize_t filterCount, const nfdnchar_t* defaultPath) {
    return NFD_ERROR;
}

nfdresult_t NFD_OpenDialogMultipleN(const nfdpathset_t** outPaths, const nfdnfilteritem_t* filterList, nfdfiltersize_t filterCount, const nfdnchar_t* defaultPath) {
    return NFD_ERROR;
}

nfdresult_t NFD_SaveDialogN(nfdnchar_t** outPath, const nfdnfilteritem_t* filterList, nfdfiltersize_t filterCount, const nfdnchar_t* defaultPath, const nfdnchar_t* defaultName) {
    return NFD_ERROR;
}

nfdresult_t NFD_PickFolderN(nfdnchar_t** outPath, const nfdnchar_t* defaultPath) {
    return NFD_ERROR;
}

const char* NFD_GetError(void) {
    return "File dialogs not supported on Android";
}

void NFD_PathSet_Free(const nfdpathset_t* pathSet) {
}

nfdresult_t NFD_PathSet_GetCount(const nfdpathset_t* pathSet, nfdpathsetsize_t* count) {
    if (count) *count = 0;
    return NFD_ERROR;
}

nfdresult_t NFD_PathSet_GetPathN(const nfdpathset_t* pathSet, nfdpathsetsize_t index, nfdnchar_t** outPath) {
    return NFD_ERROR;
}

extern "C" void uwp_ProcessEvents() {
}
