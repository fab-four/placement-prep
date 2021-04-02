# placement-prep

Placement preparation for session 2021/22

## Contribution

### Commit Style

Please read [How to Write a Git Commit Message](https://chris.beams.io/posts/git-commit/)

If you are adding any solution to a problem follow this style:

```git
github_username: commit_message
Example: singalhimanshu: add leetcode solution 102
```

### Code Header

```cpp
// @author: author_name
// @user: user_name
// Link to the question/resource

/*
* Code
*/
```

**Note**: If you are using vscode you can define a custom snippet for the language in which you solve the problems:

```json
"add header": {
    "prefix": "header",
    "body": [
        "// @author: <author_name>",
        "// @user: <user_name>",
        "// Link: $1"
    ]
}
```

Replace `<author_name>` and `<user_name>` as per yours.

### Formatter

Use clang-format before pushing the code.

- vscode : [clang-format](https://marketplace.visualstudio.com/items?itemName=xaver.clang-format)

### Extras

For leetcode problems use this extension:

- [vscode](https://marketplace.visualstudio.com/items?itemName=LeetCode.vscode-leetcode)
