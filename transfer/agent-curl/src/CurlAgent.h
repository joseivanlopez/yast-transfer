/*
 * YaST2: Core system
 *
 * Description:
 *   YaST2 SCR: Curl agent implementation
 *
 * Authors:
 *   Anas Nashif <nashif@suse.de>
 *
 * $Id$
 */

#ifndef _CurlAgent_h
#define _CurlAgent_h

#include <Y2.h>
#include <scr/SCRAgent.h>


/**
 * @short An interface class between YaST2 and Curl Agent
 */
class CurlAgent : public SCRAgent
{
private:
    /**
     * Agent private variables
     */
    bool    easySSL_val;

public:
    /**
     * Default constructor.
     */
    CurlAgent();

    /**
     * Destructor.
     */
    virtual ~CurlAgent();

    /**
     * Provides SCR Read ().
     * @param path Path that should be read.
     * @param arg Additional parameter.
     */
    virtual YCPValue Read(const YCPPath &path,
			  const YCPValue& arg = YCPNull(),
			  const YCPValue& opt = YCPNull());

    /**
     * Provides SCR Write ().
     */
    virtual YCPBoolean Write(const YCPPath &path,
			   const YCPValue& value,
			   const YCPValue& arg = YCPNull());


    /**
     * Provides SCR Execute ().
     */
    virtual YCPValue Execute(const YCPPath &path,
			     const YCPValue& value = YCPNull(),
			     const YCPValue& arg = YCPNull());

    /**
     * Provides SCR Dir ().
     */
    virtual YCPList Dir(const YCPPath& path);

    /**
     * Used for mounting the agent.
     */
    virtual YCPValue otherCommand(const YCPTerm& term);
    virtual YCPValue Get( const char *url, const char *target);
    // virtual YCPValue  Post(  const char *url, const char *post, const char *target);
    virtual string getMapValue ( const YCPMap map, const string key, const string defaultValue);
    virtual void easySSL( bool easy );

private:

};

#endif /* _CurlAgent_h */