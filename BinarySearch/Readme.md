```mermaid
flowchart TD
    A[Start] --> B{Is target == mid?}
    B -- Yes --> C[Return mid]
    B -- No --> D{target < mid}
    D -- Yes --> E[Search left half]
    D -- No --> F[Search right half]
