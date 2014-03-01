#ifndef TE_IMPORT_EXPORT_H
#define TE_IMPORT_EXPORT_H

#pragma warning( disable : 4273 4251 )

#ifdef TE_DLL
//#  pragma message("compiling tepp as dll")
#  define TE_API __declspec(dllexport)
#  define TE_DECL       __cdecl 

#else
//#  pragma message("using tepp dll")
#  define TE_API __declspec(dllimport)
#  define TE_DECL

#endif


#endif // TE_IMPORT_EXPORT_H

