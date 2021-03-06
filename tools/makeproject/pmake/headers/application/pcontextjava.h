const char PCONTEXTJAVA_STR[] = 
"/*\n"
" * Copyright 2012 - 2014 Future Interface. All rights reserved.\n"
" * This software is licensed under the terms of the MIT license.\n"
" */\n"
"package com.fi.tech;\n"
"\n"
"/**\n"
" *\n"
" */\n"
"public class PContext {\n"
"	private static final String TAG = \"PContext\";\n"
"\n"
"	/* Library state is needed for tracking pause/resume behavior */\n"
"	private static final int STATE_IDLE = 0;\n"
"	private static final int STATE_STARTING = 1;\n"
"	private static final int STATE_RUNNING = 2;\n"
"	private static final int STATE_PAUSING = 3;\n"
"	private static final int STATE_PAUSED = 4;\n"
"	private static final int STATE_RESUMING = 5;\n"
"	private static final int STATE_STOPPING = 6;\n"
"\n"
"	private int mState;\n"
"	private int mContextId;\n"
"	private String mContextName;\n"
"\n"
"	public static final boolean DEBUG = false;\n"
"	// Below enum value is to indicate the orientation value (Ref\n"
"	// http://developer.android.com/reference/android/content/pm/ActivityInfo.html#SCREEN_ORIENTATION_LANDSCAPE\n"
"	// )\n"
"	public static final int SCREEN_ORIENTATION_LANDSCAPE = 0;\n"
"	public static final int SCREEN_ORIENTATION_PORTRAIT = 1;\n"
"\n"
"	private static native void createContextNative(String contextName);\n"
"\n"
"	private static native int getContextIdByNameNative(String contextName);\n"
"\n"
"	private static native void uninitializeContextNative(int contextId);\n"
"\n"
"	private static native void pauseNative(int contextId);\n"
"\n"
"	private static native void resumeNative(int contextId);\n"
"\n"
"	private static native boolean updateNative(int contextId);\n"
"\n"
"	private static native void resizeNative(int contextId, int width, int height);\n"
"\n"
"	private static native void orientationChangeNative(int contextId,\n"
"			int orientation);\n"
"\n"
"	private static native void initializeContextNative(int contextId,\n"
"			int width, int height);\n"
"\n"
"	public PContext(String contextName) {\n"
"		mState = STATE_STARTING;\n"
"		mContextName = contextName;\n"
"		createContextNative(mContextName);\n"
"	}\n"
"\n"
"	public void initialize(int width, int height) {\n"
"		mState = STATE_STARTING;\n"
"		mContextId = getContextIdByNameNative(mContextName);\n"
"		initializeContextNative(mContextId, width, height);\n"
"		mState = STATE_RUNNING;\n"
"	}\n"
"\n"
"	public void deinitialize() {\n"
"		mState = STATE_STOPPING;\n"
"		uninitializeContextNative(mContextId);\n"
"		mState = STATE_IDLE;\n"
"		mContextId = -1;\n"
"	}\n"
"\n"
"	public boolean isInitialized() {\n"
"		return ((mState == STATE_RUNNING) || (mState == STATE_PAUSED)\n"
"				|| (mState == STATE_PAUSING) || (mState == STATE_RESUMING));\n"
"	}\n"
"\n"
"	public boolean isPaused() {\n"
"		return (mState == STATE_PAUSED);\n"
"	}\n"
"\n"
"	public void pause() {\n"
"		mState = STATE_PAUSING;\n"
"		pauseNative(mContextId);\n"
"		mState = STATE_PAUSED;\n"
"	}\n"
"\n"
"	public void resume() {\n"
"		mState = STATE_RESUMING;\n"
"		resumeNative(mContextId);\n"
"		mState = STATE_RUNNING;\n"
"	}\n"
"\n"
"	/**\n"
"	 * set the orientation . use PNativeLibrary.SCREEN_ORIENTATION_LANDSCAPE or\n"
"	 * PNativeLibrary.SCREEN_ORIENTATION_PORTRAIT\n"
"	 * \n"
"	 * @param orientation\n"
"	 */\n"
"	public void orientationChange(int orientation) {\n"
"		orientationChangeNative(mContextId, orientation);\n"
"	}\n"
"\n"
"	public void resize(int width, int height) {\n"
"		resizeNative(mContextId, width, height);\n"
"	}\n"
"\n"
"	public boolean update() {\n"
"		if (!updateNative(mContextId)) {\n"
"			mState = STATE_STOPPING;\n"
"			return false;\n"
"		}\n"
"		return true;\n"
"	}\n"
"\n"
"	public int getState() {\n"
"		return mState;\n"
"	}\n"
"\n"
"	/**\n"
"	 * @param touchEvent\n"
"	 * @param index\n"
"	 * @param id\n"
"	 * @param x\n"
"	 * @param y\n"
"	 * @param pressure\n"
"	 * @param area\n"
"	 * @param state\n"
"	 */\n"
"	public long touchEvent(int cursorCount, int state) {\n"
"		return touchEventNative(mContextId, cursorCount, state);\n"
"	}\n"
"\n"
"	/**\n"
"	 * @param touchEvent\n"
"	 * @param index\n"
"	 * @param id\n"
"	 * @param x\n"
"	 * @param y\n"
"	 * @param pressure\n"
"	 * @param area\n"
"	 * @param state\n"
"	 */\n"
"	public void touchCursor(long touchEvent, int index, int id, float x,\n"
"			float y, float pressure, float area, int state, long timeStamp) {\n"
"		touchCursorNative(mContextId, touchEvent, index, id, x, y, pressure,\n"
"				area, state, timeStamp);\n"
"	}\n"
"\n"
"	/**\n"
"	 * @param focusState\n"
"	 */\n"
"	public void focusEvent(boolean focusState) {\n"
"		focusEventNative(mContextId, focusState);\n"
"	}\n"
"\n"
"	/**\n"
"	 * @param buttonCode\n"
"	 * @param state\n"
"	 */\n"
"	public void keyEvent(int buttonCode, int state, long timeStamp) {\n"
"		keyEventNative(mContextId, buttonCode, state, timeStamp);\n"
"	}\n"
"\n"
"	/**\n"
"	 * debug function: switch Head-Up Display on or off\n"
"	 * \n"
"	 * @param state\n"
"	 */\n"
"	public void setHUD(boolean state) {\n"
"		setHUDNative(mContextId, state);\n"
"	}\n"
"\n"
"	/**\n"
"	 * debug function: switch free camera movement on or off\n"
"	 * \n"
"	 * @param state\n"
"	 */\n"
"	public void setFreeCamera(boolean state) {\n"
"		setFreeCameraNative(mContextId, state);\n"
"	}\n"
"\n"
"	public static native long touchEventNative(int contextId, int cursorCount,\n"
"			int state);\n"
"\n"
"	public static native void touchCursorNative(int contextId, long touchEvent,\n"
"			int index, int id, float x, float y, float pressure, float area,\n"
"			int state, long timeStamp);\n"
"\n"
"	public static native void focusEventNative(int contextId, boolean focusState);\n"
"\n"
"	public static native void keyEventNative(int contextId, int buttonCode,\n"
"			int state, long timeStamp);\n"
"\n"
"	public static native void setHUDNative(int contextId, boolean state);\n"
"\n"
"	public static native void setFreeCameraNative(int contextId, boolean state);\n"
"}\n"
;