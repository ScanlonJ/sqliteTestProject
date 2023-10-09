#ifndef __DATABASEDEFINES_H__
#define __DATABASEDEFINES_H__

// Defines for database function calls.
#define DB_CREATE_DATABASE_FILE           "CreateDatabaseFile"
#define DB_INITIALIZE_DATABASE_LAYOUT     "InitializeDatabaseLayout"
#define DB_ADD_MEMBER                     "AddMember"
#define DB_UPDATE_MEMBER_INFO             "UpdateMemberInfo"
#define DB_ADD_MEMBER_CLASSES             "AddMemberClasses"
#define DB_MARK_CLASS_ATTENDANCE          "MarkClassAttendance"
#define DB_PROMOTE_MEMBER                 "PromoteMember"
#define DB_SELECT_MEMBERS                 "SelectMembers"
#define DB_SELECT_MEMBER_INFO             "SelectMemberInfo"

// NVString field names
#define NV_DB_FILE_NAME                   "DatabaseFileName"
#define NV_MEMBER_ID                      "ID"
#define NV_MEMBER_NAME                    "Name"
#define NV_MEMBER_DOB                     "Date Of Birth"
#define NV_MEMBER_JOIN_DATE               "Join Date"
#define NV_MEMBER_EMAIL                   "Email"
#define NV_MEMBER_PHONE                   "Phone Number"
#define NV_MEMBER_CONTACT                 "Contact"
#define NV_MEMBER_BELT_LEVEL              "Belt Level"
#define NV_MEMBER_DATE_OF_LAST_TEST       "Date Of Last Test"
#define NV_MEMBER_CLASSES_SINCE_LAST_TEST "Classes Since Last Test"
#define NV_MEMBER_CLASSES_PURCHASED       "Classes Purchased"
#define NV_MEMBER_CLASSES_ATTENDED        "Classes Attended"
#define NV_CLASS_NUMBER_OF_STUDENTS       "Number Of Students"
#define NV_CLASS_LIST_OF_STUDENTS         "List Of Students"

#endif
