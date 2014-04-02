/*
 * Key.h
 *
 *  Created on: Apr 2, 2014
 *      Author: Sebass
 */

#ifndef KEY_H_
#define KEY_H_

#include <cstring>
using namespace std;

class Key {
public:
	Key( const char* key, const int pos, const int length );

	/*
	 * Return the key of the key object.
	 *
	 * @return the key
	 */
	const char* getKey();

	/*
	 * Set the name of the key to be associated with this object. to be used by the constructor
	 *
	 * @params the keyname
	 */
	void setKey( const char* key);
	/*
	 * Retrieve the pos associated with this key object
	 *
	 * @return the pos
	 */
	const int getPos();

	/*
	 * Set the pos to be associated with this key object, mainly to be used by constructor
	 *
	 * @params the position
	 */
	void setPos( const int pos);

	/*
	 * Retrieve the length associated with this key for access to the datafile
	 *
	 * @return the length
	 */
	const int getLength();

	/*
	 * Set the length of the key to be associated with this key, mainly to be used by constructor
	 *
	 * @params the length
	 */
	void setLength(const int length);

	/*
	 * Helper function to be used when merging the keys and searching for the keys by the
	 * keyfile.
	 *
	 * @return the ascii value of the key.
	 */
	long getAsciiValue();

	/*
	 * destructor
	 */
	virtual ~Key();
};

#endif /* KEY_H_ */
