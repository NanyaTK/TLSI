# Contributing guide
In this guide you will get an overview of the contribution workflow.

## Getting started
### Refactoring code
In principle, the following flow will pass:
1. Create an Issue
1. Create a PullRequest
1. merge after Review

### Issues
#### Create a new issue
if you spot a problem with the code, search if an issue already exists.  if a related issue doesn't exist, you can open a new issue using a relevant issue form.

#### Solve an issue
Scan through our [existing issues]() to find one that interests you. You can narrow down the search using `labels` as filters.  As a general rule, we don’t assign issues to anyone. If you find an issue to work on, you are welcome to open a PR with a fix.

### Pull Request
When you're finished with the changes, create a pull request, also known as a PR.
- First of all, we basically follow [Semantic Commit Message](https://gist.github.com/joshbuchea/6f47e86d2510bce28f8e7f42ae84c716#semantic-commit-messages) format. If you don't follow this format, your PR might be refused.
- Fill the "Ready for review" template so that we can review your PR. This template helps reviewers understand your changes as well as the purpose of your pull request.
- Don't forget to [link PR to issue](https://docs.github.com/en/issues/tracking-your-work-with-issues/linking-a-pull-request-to-an-issue) if you are solving one.
- Enable the checkbox to [allow maintainer edits](https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/allowing-changes-to-a-pull-request-branch-created-from-a-fork) so the branch can be updated for a merge.
Once you submit your PR, a Docs team member will review your proposal. We may ask questions or request additional information.
- We may ask for changes to be made before a PR can be merged, either using [suggested changes](https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/incorporating-feedback-in-your-pull-request) or pull request comments. You can apply suggested changes directly through the UI. You can make any other changes in your fork, then commit them to your branch.
- As you update your PR and apply changes, mark each conversation as [resolved](https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/commenting-on-a-pull-request#resolving-conversations).
- If you run into any merge issues, checkout this [git tutorial](https://github.com/skills/resolve-merge-conflicts) to help you resolve merge conflicts and other issues.

## Naming convention
We basically follw [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) .
