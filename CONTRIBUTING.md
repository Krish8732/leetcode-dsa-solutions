# Contributing to LeetCode DSA Solutions

Thank you for your interest in contributing to this repository! Your contributions help make this a valuable resource for everyone learning DSA.

## 🎯 How to Contribute

### Adding New Solutions

1. **Choose a Problem:**
   - Pick a LeetCode problem you've solved
   - Ensure it's not already in the repository

2. **Place in Correct Folder:**
   - Navigate to the appropriate topic folder (e.g., `Tree/`, `Arrays/`)
   - Place it in the correct difficulty subfolder (`Easy/`, `Medium/`, or `Hard/`)

3. **Follow Naming Convention:**
   ```
   {LeetCode_Number}_{ProblemName}.{extension}
   ```
   **Examples:**
   - `938_RangeSumOfBST.cpp`
   - `1_TwoSum.py`
   - `2_AddTwoNumbers.java`

4. **Include Required Sections:**
   Each solution file must include:
   - **Problem Number & Name** (LeetCode #)
   - **Difficulty Level** (Easy/Medium/Hard)
   - **Topics** (Related DSA concepts)
   - **Problem Description** (What to solve)
   - **Approach** (Algorithm explanation)
   - **Complexity Analysis** (Time & Space)
   - **Code Implementation** (Clean, commented code)
   - **Example** (Input/Output walkthrough)

5. **Code Quality Standards:**
   - Write clean, readable code
   - Add meaningful comments for complex logic
   - Include variable names that are self-explanatory
   - Test your solution on LeetCode before submitting

## 📋 Solution Template

Use this template for new solutions:

```cpp
/**
 * Problem: [Problem Name]
 * LeetCode #: [Number]
 * Difficulty: [Easy/Medium/Hard]
 * Topics: [Topic1, Topic2, Topic3]
 * 
 * Problem Description:
 * [Brief description of what needs to be solved]
 * 
 * Approach:
 * [Explain the algorithm/strategy used]
 * [Key insights and optimizations]
 * 
 * Time Complexity: O(...)
 * Space Complexity: O(...)
 * 
 * Example:
 * Input: [example input]
 * Output: [expected output]
 */

// Solution code here
```

## 💻 Git Workflow

1. **Fork the Repository**
   ```bash
   git clone https://github.com/yourusername/leetcode-dsa-solutions.git
   cd leetcode-dsa-solutions
   ```

2. **Create a Feature Branch**
   ```bash
   git checkout -b feature/add-solutions
   ```

3. **Make Your Changes**
   - Add your solution files
   - Update README.md if adding new category

4. **Commit with Meaningful Messages**
   ```bash
   git commit -m "Add Tree/Medium: 938 Range Sum of BST"
   git commit -m "Add Graph/Easy: 997 Find Town Judge"
   ```

   **Commit Message Format:**
   ```
   [Topic/Difficulty]: [LeetCode #] [Problem Name]
   ```

5. **Push to Your Fork**
   ```bash
   git push origin feature/add-solutions
   ```

6. **Open a Pull Request**
   - Provide a clear description of what you've added
   - Reference related issues if any

## ✅ Review Checklist

Before submitting a PR, ensure:

- [ ] File is in the correct topic folder
- [ ] File is in the correct difficulty subfolder
- [ ] Filename follows the naming convention
- [ ] Solution includes all required sections (Problem, Approach, Complexity, Code, Example)
- [ ] Code is tested on LeetCode and passes all test cases
- [ ] Code follows the repository's style guidelines
- [ ] Comments are meaningful and helpful
- [ ] Commit message is clear and follows the format

## 🐛 Improving Existing Solutions

If you find room for improvement in existing solutions:

1. Add alternative approaches (if significantly different)
2. Improve explanations and comments
3. Optimize time/space complexity
4. Fix any bugs or issues

Use commit messages like:
```
Optimize Tree/Medium: 938 Range Sum of BST - reduce space complexity
```

## 📚 Best Practices

- **Be Clear:** Write code and comments that others can easily understand
- **Be Efficient:** Aim for optimal time and space complexity
- **Be Thorough:** Include edge cases in examples
- **Be Humble:** Welcome feedback and suggestions

## ❓ Questions?

- Check existing issues for similar questions
- Open a new issue to discuss ideas
- Keep discussions constructive and helpful

## 🎓 Learning Goals

This repository aims to:
- Help developers practice DSA problems
- Provide clean, well-explained solutions
- Build a community of learners
- Maintain a resource for interview preparation

---

**Thank you for contributing! Together we're building an awesome learning resource.** 🚀
