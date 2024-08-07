#include <Core/logger.h>
#include <Core/asserts.h>

int main()
{
  VKW_LOG_INFO("But did you see the actual questions? %d", 2808);

  VKW_ASSERT_MSG(1 < 0, "I'm SURE 1 is less than 0... UH OH");
  return 0;
}
