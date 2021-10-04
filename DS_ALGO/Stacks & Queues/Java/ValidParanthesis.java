import java.util.*;

public class ValidParanthesis {
  public static void main(String[] args) {
    String expression = "[{()}]({2})[]";
    if (isBalanced(expression))
      System.out.println("Balanced.");
    else
      System.out.println("not Balanced.");
  }

  public static boolean isBalanced(String expression) {
    Stack<Character> stack = new Stack<>();
    char topOfStack;
    for (int i = 0; i < expression.length(); i++) {
      char currentCharacter = expression.charAt(i);
      if (currentCharacter == '(' || currentCharacter == '{' || currentCharacter == '[')
        stack.push(currentCharacter);
      else {
        if (stack.isEmpty())
          return false;
        switch (currentCharacter) {
          case ')':
            topOfStack = stack.pop();
            if (topOfStack != '(')
              return false;
            break;
          case '}':
            topOfStack = stack.pop();
            if (topOfStack != '{')
              return false;
            break;
          case ']':
            topOfStack = stack.pop();
            if (topOfStack != '[')
              return false;
            break;
        }
      }
    }
    return stack.isEmpty();
  }
}